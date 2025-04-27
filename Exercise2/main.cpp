#include <cmath> 
#include <iostream>
#include <numeric> 
#include <iostream>
#include <sstream>
#include <chrono> 
#include "SortingAlgorithm.hpp"
using namespace std;

template<typename T>
string ArrayToString(const vector<T>& v)
{
    string str;
    ostringstream toString;
    toString << "[ ";
    for (const T& e: v)
        toString << e << " ";
    toString << "]";

    return toString.str();
}

struct ClassObj{
    double value;
};

inline bool operator< (const ClassObj& lhs, const ClassObj& rhs) { return lhs.value < rhs.value; }

int main(int argc, char *argv[])
{
	cout <<"argc:" << argc << endl;
	if (argc < 2) {
    cerr << "Error: Please provide the size of the vector as an argument." << endl;
    return -1;
	}
	for(unsigned int a=0; a < argc;a++)
		cout << argv[a] << endl;

    size_t m = 10000;
	istringstream st(argv[1]);
	st >> m;
	//vettore randomico
	vector<double> v1(m);
	for(unsigned int i =0; i<m;i++)
		v1[i] =rand(); 
	
    //vettore ordinato
	vector<int> v2(m);
    std::iota(v2.begin(),v2.end(),1);
    cout << "v2: " << endl;
    cout << ArrayToString(v2) << endl;
	
	//ordinato al contrario
	vector<int> v3(m);
    std::iota(v3.rbegin(),v3.rend(),1);
    cout << "v3: " << endl;
    cout << ArrayToString(v3) << endl;
	
	unsigned int num_experiment = 100;

    double time_elapsed_selection_v1 = 0.0;
    for(unsigned int t = 0; t < num_experiment; t++)
    {
        vector<double> v(v1);

        std::chrono::steady_clock::time_point start_time = std::chrono::steady_clock::now();
        SortLibrary::BubbleSort<double>(v);
        std::chrono::steady_clock::time_point end_time = std::chrono::steady_clock::now();
        time_elapsed_selection_v1 += std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time).count();
    }
    time_elapsed_selection_v1 /= num_experiment;

    cout << "Bubble Sort - v1: " << time_elapsed_selection_v1 << endl;

    double time_elapsed_selection_v2 = 0.0;
    for(unsigned int t = 0; t < num_experiment; t++)
    {
        vector<int> v(v2);

        std::chrono::steady_clock::time_point start_time = std::chrono::steady_clock::now();
        SortLibrary::BubbleSort<int>(v);
        std::chrono::steady_clock::time_point end_time = std::chrono::steady_clock::now();
        time_elapsed_selection_v2 += std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time).count();
    }
    time_elapsed_selection_v2 /= num_experiment;

    cout << "Bubble Sort - v2: " << time_elapsed_selection_v2 << endl;


    double time_elapsed_selection_v3 = 0.0;
    for(unsigned int t = 0; t < num_experiment; t++)
    {
        vector<int> v(v3);

        std::chrono::steady_clock::time_point start_time = std::chrono::steady_clock::now();
        SortLibrary::BubbleSort<int>(v);
        std::chrono::steady_clock::time_point end_time = std::chrono::steady_clock::now();
        time_elapsed_selection_v3 += std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time).count();
    }
    time_elapsed_selection_v3 /= num_experiment;

    cout << "Bubble Sort - v3: " << time_elapsed_selection_v3 << endl;

    double time_elapsed_insertion_v1 = 0.0;
    for(unsigned int t = 0; t < num_experiment; t++)
    {
        vector<double> v(v1);

        std::chrono::steady_clock::time_point start_time = std::chrono::steady_clock::now();
        SortLibrary::HeapSort<double>(v);
        std::chrono::steady_clock::time_point end_time = std::chrono::steady_clock::now();
        time_elapsed_insertion_v1 += std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time).count();
    }
    time_elapsed_insertion_v1 /= num_experiment;

    cout << "Heap Sort - v1: " << time_elapsed_insertion_v1 << endl;

    double time_elapsed_insertion_v2 = 0.0;
    for(unsigned int t = 0; t < num_experiment; t++)
    {
        vector<int> v(v2);

        std::chrono::steady_clock::time_point start_time = std::chrono::steady_clock::now();
        SortLibrary::HeapSort<int>(v);
        std::chrono::steady_clock::time_point end_time = std::chrono::steady_clock::now();
        time_elapsed_insertion_v2 += std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time).count();
    }
    time_elapsed_insertion_v2 /= num_experiment;

    cout << "Heap Sort - v2: " << time_elapsed_insertion_v2 << endl;


    double time_elapsed_insertion_v3 = 0.0;
    for(unsigned int t = 0; t < num_experiment; t++)
    {
        vector<int> v(v3);

        std::chrono::steady_clock::time_point start_time = std::chrono::steady_clock::now();
        SortLibrary::HeapSort<int>(v);
        std::chrono::steady_clock::time_point end_time = std::chrono::steady_clock::now();
        time_elapsed_insertion_v3 += std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time).count();
    }
    time_elapsed_insertion_v3 /= num_experiment;

    cout << "Heap Sort - v3: " << time_elapsed_insertion_v3 << endl;


    return 0;

}



