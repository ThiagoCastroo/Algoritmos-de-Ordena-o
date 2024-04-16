#include <iostream>
#include <vector> 
#include <ctime> // Biblioteca para medir o tempo
#include <cstdlib> // Biblioteca para funções de utilidade, como rand() que vai ser ultilizado para criar o vetor

using namespace std;

// Função para criar vetor aleatório
vector<int> vetorAleatorio(int n){
    vector<int> v(n);  // Criando um vetor de tamanho n
    for (int i = 0; i < n; ++i){
        v[i] = rand() % 1000 + 1;  // Gera números aleatórios entre 1 e 1000
    }
    return v; 
}

// Função para trocar elementos
void swap(int& a, int& b){
    int temp = a;
    a = b; 
    b = temp;
}

// Bubble Sort
void bubbleSort(vector<int>& v){
    int n = v.size();
    for(int i = 0; i < n - 1; ++i){
        for (int j = 0; j < n - i - 1; ++j){
            if(v[j] > v[j + 1]){
                swap(v[j], v[j + 1]);
            } 
        }
    }
}

// Função para testar o tempo de execução do Bubble Sort
void testBubbleSort(const vector<int>& arr, int size){
    vector<int> temp = arr;  // Copia do vetor original
    clock_t start = clock();  // Obtendo o tempo inicial
    bubbleSort(temp);        // Chamando a função de ordenação
    clock_t end = clock();    // Obtendo o tempo final
    double elapsedTime = double(end - start) / CLOCKS_PER_SEC;  // Calculando o tempo decorrido

    cout << "Bubble Sort para vetor de tamanho " << size << ": " << elapsedTime << " segundos" << endl;  // Imprimindo o tempo decorrido
}

// Insertion Sort
void insertionSort(vector<int>& v){
    int n = v.size();
    for (int i = 1; i < n; ++i){
        int key = v[i];
        int j = i - 1;

        while (j >= 0 && v[j] > key){
            v[j + 1] = v[j];
            j = j - 1;
        }
        v[j + 1] = key;
    }
}

// Função para testar o tempo de execução do Insertion Sort
void testInsertionSort(const vector<int>& arr, int size){
    vector<int> temp = arr;  // Copia do vetor original
    clock_t start = clock();  // Obtendo o tempo inicial
    insertionSort(temp);     // Chamando a função de ordenação
    clock_t end = clock();    // Obtendo o tempo final
    double elapsedTime = double(end - start) / CLOCKS_PER_SEC;  // Calculando o tempo decorrido

    cout << "Insertion Sort para vetor de tamanho " << size << ": " << elapsedTime << " segundos" << endl;  // Imprimindo o tempo decorrido
}

// Selection Sort
void selectionSort(vector<int>& v){
    int n = v.size();
    for (int i = 0; i < n - 1; ++i){
        int min_idx = i;
        for (int j = i + 1; j < n; ++j){
            if (v[j] < v[min_idx]){
                min_idx = j;
            }
        }
        if (min_idx != i){
            swap(v[i], v[min_idx]);
        }
    }
}

// Função para testar o tempo de execução do Selection Sort
void testSelectionSort(const vector<int>& arr, int size){
    vector<int> temp = arr;  // Copia do vetor original
    clock_t start = clock();  // Obtendo o tempo inicial
    selectionSort(temp);      // Chamando a função de ordenação
    clock_t end = clock();    // Obtendo o tempo final
    double elapsedTime = double(end - start) / CLOCKS_PER_SEC;  // Calculando o tempo decorrido

    cout << "Selection Sort para vetor de tamanho " << size << ": " << elapsedTime << " segundos" << endl;  // Imprimindo o tempo decorrido
}

// Shell Sort
void shellSort(vector<int>& v){
    int n = v.size();
    for (int h = n/2; h > 0; h /= 2){
        for (int i = h; i < n; ++i){
            int temp = v[i];
            int j;
            for (j = i; j >= h && v[j - h] > temp; j -= h){
                v[j] = v[j - h];
            }
            v[j] = temp;
        }
    }
}

// Função para testar o tempo de execução do Shell Sort
void testShellSort(const vector<int>& arr, int size){
    vector<int> temp = arr;  // Copia do vetor original
    clock_t start = clock();  // Obtendo o tempo inicial
    shellSort(temp);          // Chamando a função de ordenação
    clock_t end = clock();    // Obtendo o tempo final
    double elapsedTime = double(end - start) / CLOCKS_PER_SEC;  // Calculando o tempo decorrido

    cout << "Shell Sort para vetor de tamanho " << size << ": " << elapsedTime << " segundos" << endl;  // Imprimindo o tempo decorrido
}

// Merge Sort
void merge(vector<int>& v, int low, int high, int mid){
    int i, j, k;
    int c[high-low+1];
    i = low;
    k = 0;
    j = mid + 1;
    
    while (i <= mid && j <= high){
        if (v[i] < v[j]){
            c[k++] = v[i++];
        }
        else{
            c[k++] = v[j++];
        }
    }
    
    while (i <= mid){
        c[k++] = v[i++];
    }
    
    while (j <= high){
        c[k++] = v[j++];
    }
    
    for (i = low, j = 0; i <= high; ++i, ++j){
        v[i] = c[j];
    }
}

void mergeSort(vector<int>& v, int low, int high){
    if(low < high){
        int mid = (low + high) / 2;
        mergeSort(v, low, mid);
        mergeSort(v, mid + 1, high);
        merge(v, low, high, mid);
    }
}

// Função para testar o tempo de execução do Merge Sort
void testMergeSort(const vector<int>& arr, int size){
    vector<int> temp = arr;  // Copia do vetor original
    clock_t start = clock();  // Obtendo o tempo inicial
    mergeSort(temp, 0, size - 1);  // Chamando a função de ordenação
    clock_t end = clock();    // Obtendo o tempo final
    double elapsedTime = double(end - start) / CLOCKS_PER_SEC;  // Calculando o tempo decorrido

    cout << "Merge Sort para vetor de tamanho " << size << ": " << elapsedTime << " segundos" << endl;  // Imprimindo o tempo decorrido
}

// Quick Sort
int partition(vector<int>& v, int low, int high){
    int pivot = v[high];
    int i = low - 1;
    for (int j = low; j <= high - 1; ++j){ 
        if (v[j] < pivot){
            ++i;
            swap(v[i], v[j]);
        }
    }
    swap(v[i + 1], v[high]);
    return i + 1;
}

void quickSort(vector<int>& v, int low, int high){
    if (low < high){
        int pi = partition(v, low, high);
        quickSort(v, low, pi - 1);
        quickSort(v, pi + 1, high);
    }
}

// Função para testar o tempo de execução do Quick Sort
void testQuickSort(const vector<int>& arr, int size){
    vector<int> temp = arr;  // Copia do vetor original
    clock_t start = clock();  // Obtendo o tempo inicial
    quickSort(temp, 0, size - 1);  // Chamando a função de ordenação
    clock_t end = clock();    // Obtendo o tempo final
    double elapsedTime = double(end - start) / CLOCKS_PER_SEC;  // Calculando o tempo decorrido

    cout << "Quick Sort para vetor de tamanho " << size << ": " << elapsedTime << " segundos" << endl;  // Imprimindo o tempo decorrido
}

int main(){
    // Tamanhos dos vetores para os testes
    vector<int> sizes = {10000, 15000, 25000, 50000, 75000, 100000, 125000, 150000, 175000, 200000};

    for(int size : sizes){  // Loop para cada tamanho de vetor
        vector<int> arr = vetorAleatorio(size);  // Criando um vetor aleatório
        testBubbleSort(arr, size);      // Testando o Bubble Sort
        testInsertionSort(arr, size);   // Testando o Insertion Sort
        testSelectionSort(arr, size);   // Testando o Selection Sort
        testShellSort(arr, size);       // Testando o Shell Sort
        testMergeSort(arr, size);       // Testando o Merge Sort
        testQuickSort(arr, size);       // Testando o Quick Sort
        cout << endl;  // Imprimindo uma linha em branco entre os resultados
    }

    return 0;
}
