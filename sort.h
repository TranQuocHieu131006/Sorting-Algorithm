#include <iostream>
#include <cstring>
#include <chrono>
#include <thread>
#include <cstdlib>

// RADIX SORT
int getMax(int arr[], int n, unsigned long long &comp) {
    int maxVal = arr[0]; 
    for (int i = 1; i < n; i++, comp++) {  
        comp++; 
        if (arr[i] > maxVal) {
            maxVal = arr[i];
        }
    }
    return maxVal;
}

void countingSort(int arr[], int n, int exp, unsigned long long &comp) {
    int output[n]; 
    int count[10] = {0}; 

    for (int i = 0; i < n; i++, comp++) {
        count[(arr[i] / exp) % 10]++;
    }


    for (int i = 1; i < 10; i++, comp++) { 
        count[i] += count[i - 1];
    }
 
    for (int i = n - 1; i >= 0; i--, comp++) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }
  
    for (int i = 0; i < n; i++, comp++) {
        arr[i] = output[i];
    }

}


void radixSort(int arr[], int n, unsigned long long &comp) {
    int maxVal = getMax(arr, n, comp);


    for (int exp = 1; maxVal / exp > 0; exp *= 10, comp++) { 
        countingSort(arr, n, exp, comp);
    }
}


//QUICK SORT

int medianOfThree(int arr[], int left, int right, unsigned long long &comp) {
    int mid = left + (right - left) / 2;
    comp += 2;
    if ((arr[left] < arr[mid]) ^ (arr[left] < arr[right])) 
        return left;
    
    comp += 2;
    if ((arr[mid] < arr[left]) ^ (arr[mid] < arr[right])) 
        return mid;
    
    return right;
}



int partition(int arr[], int left, int right, unsigned long long &comp) {
    int pivotIndex = medianOfThree(arr, left, right, comp);
    int pivot = arr[pivotIndex];
    swap(arr[pivotIndex], arr[right]); 

    int i = left - 1;
    for (int j = left; j < right; j++ && comp++) {
        comp++;
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[right]);
    return i + 1;
}

void quickSort(int arr[], int left, int right, unsigned long long &comp) {
    comp++;
    if (left < right) {
        int pivotIndex = partition(arr, left, right, comp);
        
        quickSort(arr, left, pivotIndex - 1, comp);
        quickSort(arr, pivotIndex + 1, right, comp);
    }
}

void quickSort(int arr[], int n, unsigned long long &comp) {
    quickSort(arr, 0, n - 1, comp);
}

//INSERTION SORT 
void insertionSort(int arr[], int n, unsigned long long &comp) {
    for (int i = 1; i < n; i++) {
        comp++;
        int key = arr[i];
        int j = i - 1;

        // Di chuyển các phần tử lớn hơn key sang phải
        while (j >= 0 && arr[j] > key) {
            comp+=2;
            arr[j + 1] = arr[j];
            j--;
        }
        comp+=2;
        arr[j + 1] = key;
    }
    comp++;
}