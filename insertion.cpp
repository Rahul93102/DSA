#include<iostream>
#include<queue>
using namespace std;

class heap{ 
    public:
    int arr[100];
    int size;

    heap(){ 
        size = 0;
        arr[0] = -1;
    }

    void insertion(int elem){ // for maxheap
        size = size + 1; // initial 0 elem is -1 then we start insertion from first elem
        int index = size;
        arr[index] = elem;
        
        while(index > 1){ 
            int parent_idx = index / 2;
            if(arr[index] > arr[parent_idx]){ 
                swap(arr[index], arr[parent_idx]);
                index = parent_idx;
            } else { 
                return;
            }
        }
    }

    void deletion(){ 
        if(size == 0){ 
            cout << "deletion is nothing" << endl;
            return;
        }
        // step - 1 store last elem in first ones as already first pos is -1 there
        arr[1] = arr[size];
        size--; // remove last pos
        int i = 1;
        while(i <= size){ 
            int left_index = 2 * i; 
            int right_index = 2 * i + 1;

            int largest = i;

            if(left_index <= size && arr[left_index] > arr[largest]){ 
                largest = left_index;
            }
            if(right_index <= size && arr[right_index] > arr[largest]){ 
                largest = right_index;
            }

            if(largest != i){ 
                swap(arr[i], arr[largest]);
                i = largest;
            } else {
                return;
            }
        }
    }

    void heapify(int arr[], int n, int i){ 
        int largest = i;
        int left = 2 * i; // as per 1st indexing
        int right = 2 * i + 1;

        if(left <= n && arr[left] > arr[largest]){ 
            largest = left;
        }
        if(right <= n && arr[right] > arr[largest]){ 
            largest = right;
        }

        if(largest != i){
            swap(arr[i], arr[largest]);
            heapify(arr, n, largest);
        }
    }

    void heapsort(int arr[], int n) { 
        // Build the max-heap
        for(int i = n / 2; i > 0; i--) { 
            heapify(arr, n, i);
        }

        int size = n;
        for(int i = size; i > 1; i--) { 
            swap(arr[1], arr[i]); // Move current root to end
            size--; // Reduce the size of the heap
            heapify(arr, size, 1); // Heapify the root element with the reduced heap
        }
    }

    void prints(){ 
        for(int i = 1; i <= size; i++){ 
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main(){ 
    heap h;
    // h.insertion(50);
    // h.insertion(55);
    // h.insertion(53);
    // h.insertion(52);
    // h.insertion(54);
    // h.deletion();
    // h.prints();

    int n = 5;
    int arr[6] = {-1, 54, 53, 55, 52, 50};
    for(int i = n / 2; i > 0; i--){  // arr elem from n/2 to n elem are leaf they do not need, they are already max heap as solo
        h.heapify(arr, n, i);
    }
    for(int i = 1; i <= n; i++){ 
        cout << arr[i] << " ";
    }
    cout << endl;

    h.heapsort(arr,n);
    cout << " new array : " << endl;
    for(int i = 1; i <= n; i++){ 
        cout << arr[i] << " ";
    }
    cout << endl;


// max heap
    // priority_queue<int>pq;
    // pq.push(4);
    // pq.push(2);
    // pq.push(5);
    // pq.push(3);

    // cout << " Element at top: " << pq.top() << endl;
    // pq.pop();
    // cout << " Element at top: " << pq.top() << endl;
    // if(pq.empty()){ 
    //     cout << " It's empty " << endl;
    // }else { 
    //     cout << " size of pq : " <<pq.size() << endl;
    // }


    // min heapp
    priority_queue<int,vector<int>,greater<int> >pq;
    pq.push(4);
    pq.push(2);
    pq.push(5);
    pq.push(3);

    cout << " Element at top: " << pq.top() << endl;
    pq.pop();
    cout << " Element at top: " << pq.top() << endl;
    if(pq.empty()){ 
        cout << " It's empty " << endl;
    }else { 
        cout << " size of pq : " <<pq.size() << endl;
    }



}
