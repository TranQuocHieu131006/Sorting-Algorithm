#include "DataGenerator.h"
#include "sort.h"

void write_down_array(std::string fileName, int a[], int n){
    std::ofstream outFile(fileName);
    outFile << n << "\n";
    for(int i = 0 ; i < n ; i++){
        outFile << a[i] << " ";
    }
    outFile.close();
}
int get_number_of_element(std::string fileName){
    std::ifstream inFile(fileName);
    int n;
    inFile >> n;
    inFile.close();
    return n;
}

bool check_file(char a[]){
    std::string str(a);
    return (str.find('.') == std::string::npos);
    //Return true if it is a number 
    //Return false if it is a file(have '.')
}
void check_output_parameter(char c[]){
    std::string str(c);
    if(str == "-time" || str == "-both"){
        std::cout << "Running time : ...   (caculating)";
    }
    if(str == "-comp"){
        std::cout << "Comparisions : ...   (caculating)";
    }
}
void check_output_parameter(char c[], double time,unsigned long long comp){
    std::string str(c);
    if(str == "-time"){
        std::cout << "\r" << std::string(40, ' ') << "\r"; // Xóa dòng bằng khoảng trắng
        std::cout << "Running time : ";
        std::cout << time << " ms" << std::endl;
    }
    if(str == "-both"){
        std::cout << "\r" << std::string(40, ' ') << "\r"; // Xóa dòng bằng khoảng trắng
        std::cout << "Running time : ";
        std::cout << time << " ms" << std::endl;
        std::cout << "Comparisions : ";
        std::cout << comp << std::endl;
    }
    if(str == "-comp"){
        std::cout << "\r" << std::string(40, ' ') << "\r"; // Xóa dòng bằng khoảng trắng
        std::cout << "Comparisions : ";
        std::cout << comp << std::endl;
    }
}

int* readfile(std::string fileName){
    std::ifstream inFile(fileName);
    int n; 
    inFile >> n ;
    int *array = new int[n];
    for(int i = 0 ; i < n ; i++){
        inFile >> array[i];
    }
    inFile.close();
    return array;
}

std::string read_sort(char c[]){

    std::string str(c);

    if(str == "bubble-sort") str = "Bubble Sort";
    if(str == "insertion-sort") str = "Insertion Sort";
    if(str == "binary-insertion-sort") str = "Binary Insertion Sort";
    if(str == "selection-sort") str = "Selection Sort,";
    if(str == "shaker-sort") str = "Shaker Sort";
    if(str == "shell-sort") str = "Shell Sort";
    if(str == "heap-sort") str = "Heap Sort";
    if(str == "radix-sort") str = "Radix Sort";
    if(str == "quick-sort") str = "Quick Sort";
    if(str == "counting-sort") str = "Counting Sort";
    if(str == "flash-sort") str = "Flash Sort";
    if(str == "merge-sort") str = "Merge Sort";

    return str;
}

std::string read_generate(char c[]){
    std::string str(c);
    if(str == "-rand") str = "Randomized data";
    if(str == "-nsorted") str = "Nearly sorted data";
    if(str == "-sorted") str = "Sorted data";
    if(str == "-rev") str = "Reverse sorted data";
    return str;
}
void select_sort_algorithms(char c[] , int *array, int n,unsigned long long &comp){

    std::string str(c);

    if(str == "bubble-sort"){
        //bubbleSort(array, n, comp);
    }
    if(str == "insertion-sort"){
        insertionSort(array, n, comp);
    }
    if(str == "binary-insertion-sort"){
        
    }
    if(str == "selection-sort"){
        
    }
    if(str == "shaker-sort"){
       
    }
    if(str == "shell-sort"){
        
    }
    if(str == "heap-sort"){
        
    }
    if(str == "radix-sort"){
        radixSort(array, n, comp);
    }
    if(str == "quick-sort"){
        quickSort(array, n, comp);
    }
    if(str == "counting-sort"){
        
    }
    if(str == "flash-sort"){
        
    }
    if(str == "merge-sort"){
        
    }

}

void using_generate(char c[],int *& array, int n){
    std::string str(c);
    if(str == "-rand"){
        GenerateRandomData(array,n);
    }
    if(str == "-nsorted"){
        GenerateNearlySortedData(array,n);
    }
    if(str == "-sorted"){
        GenerateSortedData(array,n);
    }
    if(str == "-rev"){
        GenerateReverseData(array,n);
    }
}

void command_1(int argc, char *c[]){

    std::string algo_name = read_sort(c[2]);
    std::string fileName = std::string (c[3]);
    int n = get_number_of_element(fileName);
    int *array = readfile(fileName);
    unsigned long long comp = 0;

    std::cout << "ALGORITHM MODE\n" ;
    std::cout << "Algorithm: " << algo_name << "\n";
    std::cout << "Input file: " << fileName << "\n";
    std::cout << "Input size: " << n << "\n";
    std::cout << "------------------------------\n";

    check_output_parameter(c[4]);

    auto start = std::chrono::high_resolution_clock::now();

    select_sort_algorithms(c[2], array, n, comp);
    write_down_array("output.txt", array, n);

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> duration = end - start;
    double time = duration.count();

    check_output_parameter(c[4], time, comp);   

    delete array;
}

void command_2(int argc, char *c[]){
    //Read Input size
    int n = std::stoi(c[3]);
    std::string algo_name = read_sort(c[2]);
    int *array = new int[n]; 
    std::string order = read_generate(c[4]);
    using_generate(c[4], array, n);
    unsigned long long comp = 0;

    std::cout << "ALGORITHM MODE\n" ;
    std::cout << "Algorithm: " << algo_name << "\n";
    std::cout << "Input size: " << n << "\n";
    std::cout << "Input order: " << order << "\n";
    std::cout << "------------------------------\n";

    check_output_parameter(c[5]);

    
    write_down_array("input.txt", array, n);

    auto start = std::chrono::high_resolution_clock::now();

    select_sort_algorithms(c[2], array, n, comp);
    write_down_array("output.txt", array, n);

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> duration = end - start;
    double time = duration.count();

    
    check_output_parameter(c[5], time, comp);

    delete array;
}


void command_3(int argc, char *c[]){
    //Read Input size
    int n = std::stoi(c[3]);
    std::string algo_name = read_sort(c[2]);
    int *array = new int[n]; 
    unsigned long long comp;
    std::cout << "ALGORITHM MODE\n" ;
    std::cout << "Algorithm: " << algo_name << "\n";
    std::cout << "Input size: " << n << "\n";

    //RANDOM
    comp = 0;
    std::cout << "\nInput order: " << "Randomize\n";
    std::cout << "------------------------------\n";
    check_output_parameter(c[4]);
    GenerateRandomData(array, n);
    write_down_array("input_1.txt", array, n);
    auto start = std::chrono::high_resolution_clock::now();

    select_sort_algorithms(c[2],array, n, comp);

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> duration = end - start;
    double time = duration.count();


    check_output_parameter(c[4], time, comp);

    //NEARLY SORTED
    comp = 0;
    std::cout << "\nInput order: " << "Nearly sorted\n";
    std::cout << "------------------------------\n";
    check_output_parameter(c[4]);
    GenerateNearlySortedData(array, n);
    write_down_array("input_2.txt", array, n);
    start = std::chrono::high_resolution_clock::now();

    select_sort_algorithms(c[2],array, n, comp);

    end = std::chrono::high_resolution_clock::now();
    duration = end - start;
    time = duration.count();

    check_output_parameter(c[4], time, comp);

    //SORTED
    comp = 0;
    std::cout << "\nInput order: " << "Sorted\n";
    std::cout << "------------------------------\n";
    GenerateSortedData(array, n);
    write_down_array("input_3.txt", array, n);
    start = std::chrono::high_resolution_clock::now();

    select_sort_algorithms(c[2],array, n, comp);

    end = std::chrono::high_resolution_clock::now();

    duration = end - start;
    time = duration.count();

    check_output_parameter(c[4], time, comp);

    //REVERSED
    comp = 0;
    std::cout << "\nInput order: " << "Revered\n";
    std::cout << "------------------------------\n";
    check_output_parameter(c[4]);
    GenerateReverseData(array, n);
    write_down_array("input_4.txt", array, n);
    start = std::chrono::high_resolution_clock::now();

    select_sort_algorithms(c[2],array, n, comp);

    end = std::chrono::high_resolution_clock::now();

    duration = end - start;
    time = duration.count();

    check_output_parameter(c[4], time, comp);

    delete array;

}
void command_4(int argc, char *c[]) {
    std::string algo_name_1 = read_sort(c[2]);
    std::string algo_name_2 = read_sort(c[3]);
    std::string fileName = std::string(c[4]);
    int n = get_number_of_element(fileName);
    int *array1 = readfile(fileName);
    int *array2 = new int[n];
    memcpy(array2, array1, n * sizeof(int));
    unsigned long long comp_1 = 0;
    unsigned long long comp_2 = 0;
    
    std::cout << "COMPARE MODE\n";
    std::cout << "Algorithm: " << algo_name_1 << " | " << algo_name_2 << "\n";
    std::cout << "Input file: " << fileName << "\n";
    std::cout << "Input size: " << n << "\n";
    std::cout << "------------------------------\n";
    std::cout << "Running time : ...   (caculating)";
    
    auto start = std::chrono::high_resolution_clock::now();
    select_sort_algorithms(c[2], array1, n, comp_1);
    auto end = std::chrono::high_resolution_clock::now();
    
    double time_1 = std::chrono::duration<double, std::milli>(end - start).count();
    
    start = std::chrono::high_resolution_clock::now();
    select_sort_algorithms(c[3], array2, n, comp_2);
    end = std::chrono::high_resolution_clock::now();
    
    double time_2 = std::chrono::duration<double, std::milli>(end - start).count();
    
    std::cout << "\r" << std::string(40, ' ') << "\r";
    std::cout << "Running time : " << time_1 << " ms" << " | " << time_2 << " ms" << std::endl;
    std::cout << "Comparisions : " << comp_1 << " | " << comp_2 << std::endl;
    
    delete[] array1;
    delete[] array2;
}

#include <chrono>

void command_5(int argc, char *c[]) {
    std::string algo_name_1 = read_sort(c[2]);
    std::string algo_name_2 = read_sort(c[3]);
    std::string fileName = std::string(c[4]);
    int n = std::stoi(c[4]);
    int *array1 = new int[n];
    using_generate(c[5], array1, n);
    int *array2 = new int[n];
    memcpy(array2, array1, n * sizeof(int));
    write_down_array("input.txt", array1, n);
    unsigned long long comp_1 = 0;
    unsigned long long comp_2 = 0;
    std::cout << "COMPARE MODE\n";
    std::cout << "Algorithm: " << algo_name_1 << " | " << algo_name_2 << "\n";
    std::cout << "Input size: " << n << "\n";
    std::cout << "Input order: " << read_generate(c[5]) << "\n";
    std::cout << "------------------------------\n";
    std::cout << "Running time : ...   (caculating)";
    
    auto start = std::chrono::high_resolution_clock::now();
    select_sort_algorithms(c[2], array1, n, comp_1);
    auto end = std::chrono::high_resolution_clock::now();
    
    double time_1 = std::chrono::duration<double, std::milli>(end - start).count();
    
    start = std::chrono::high_resolution_clock::now();
    select_sort_algorithms(c[3], array2, n, comp_2);
    end = std::chrono::high_resolution_clock::now();
    
    double time_2 = std::chrono::duration<double, std::milli>(end - start).count();
    
    std::cout << "\r" << std::string(40, ' ') << "\r";
    std::cout << "Running time : " << time_1 << " ms" << " | " << time_2 << " ms" << std::endl;
    std::cout << "Comparisions : " << comp_1 << " | " << comp_2 << std::endl;
    
    delete[] array1;
    delete[] array2;
}

void read_command(int n, char* c[]){

    //Check Algorithm mode or Comparison mode 
    if(c[1][1] == 'a'){
        //Check command 1 & 3 or command 2
        if(n == 5)  //Command 1 & 3
        {
            //Check command 1 or 3
            if(check_file(c[3])) //Command 3
            {
                command_3(n, c);
            }

            else  //Command 1
            {
                command_1(n, c);
            }
        }
        //Check command 2
        if(n == 6){
            command_2(n, c);
        }
    }
    else{
        if(n == 5){
            command_4(n,c);
        }
        else{
            command_5(n,c);
        }
    }

}

int main(int argc, char* argv[]) {
    read_command(argc, argv);

    return 0;
}
