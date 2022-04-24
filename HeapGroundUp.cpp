#include <iostream>
#include <cmath>

using namespace std;

class Minheap{
public:
    int *datas;
    int capacity;
    int heap_size;
    int valo;

    Minheap(int i){
        capacity = i;
        heap_size = 0;
        datas = new int[i];

    }

    void linear_search(int value)
    {
        for(int i = 0; i< heap_size; i++){
            if(datas[i] == value)
            {
                cout << "We found the value and the index is: "<< i <<endl;
                return;
            }
        }
        cout << "The heap doesn't contain the value you inputted! "<<endl;
        return;
    }

    void print_heap()
    {
        cout <<"The heap stored in an array contains: ";
        for(int i =0 ; i< heap_size; i++)
        {
            cout << datas[i] << " ";
        }
        cout << endl;
    }

    int height() // typical formula
    {
        return ceil(log2(heap_size + 1)-1);
    }

    int parent_index(int particular_index)
    {
        return((particular_index - 1)/2);
    }

    int right_index(int particular_index)
    {
        return(2*particular_index +2);
    }

    int left_index(int particular_index)
    {
        return(2*particular_index +1);
    }

    int get_min(){return datas[0];}

    void swap(int& x, int& y)
    {
        int temp;
        temp = x;
        x = y;
        y = temp;
    }

    void insert_key(int value)
    {
        if(heap_size == capacity)
        {
            cout << "Heap overflow" << endl;
            return;
        }
        heap_size++;
        int index = heap_size - 1;
        datas[index] = value;
        while(index !=0 && datas[parent_index(index)]>datas[index])
        {
            swap(datas[index], datas[parent_index(index)]);
            index = parent_index(index);
        }
    }

    int extract_min()
    {
        if(heap_size == 0)
            return INT16_MAX;
        if(heap_size == 1) {
            heap_size--;
            return datas[0];
        }
        int root = datas[0];
        datas[0] = datas[heap_size-1];
        heap_size--;
        min_heapify(0);
        return root;
    }

    int min_heapify(int start_index)
    {
        int index_at_left = left_index(start_index);
        int index_at_right = right_index(start_index);
        int smallest_index = start_index;

        if(index_at_left < heap_size && datas[index_at_left] < datas[start_index])
            smallest_index = index_at_right;
        if(index_at_right < heap_size && datas[index_at_right] < datas[smallest_index])
            smallest_index = index_at_right;
        if(smallest_index != start_index) {
            swap(datas[smallest_index], datas[start_index]);
            min_heapify(smallest_index);
        }

    }

    void delete_key(int target_index)
    {
        int very_small = INT16_MIN;
        decrease_key(target_index, very_small);
        extract_min();
    }
    void decrease_key(int target_index, int very_small)
    {
        datas[target_index] = very_small;
        while(target_index !=0 && datas[parent_index(target_index)]>datas[target_index])
        {
            swap(datas[parent_index(target_index)],datas[target_index]);
            target_index = parent_index(target_index);
        }

    }

};


int main()
{
    int s;
    cout <<"Size of Minheap: ";
    cin >> s;
    Minheap obj(s);
    cout << "Minheap is created!";

    int option,insert_value;
    do
    {
        cout << "What operation do you want to perform? " <<
             " Select Option number. Enter 0 to exit." << endl;
        cout << "1. Insert Key/Node" << endl;
        cout << "2. Search Key/Node" << endl;
        cout << "3. Delete Key/Node" << endl;
        cout << "4. Get Min" << endl;
        cout << "5. Extract Min" << endl;
        cout << "6. Height of Heap" << endl;
        cout << "7. Print/Traversal Heap values" << endl;
        cout << "8. Clear Screen" << endl;
        cout << "0. Exit Program" << endl;

        cin >> option;

        switch (option) {
            case 0:
                break;
            case 1:
                cout << "INSERT Operation -" << endl;
                cout << "Enter VALUE to INSERT in HEAP: ";
                cin >> insert_value;
                obj.insert_key(insert_value);
                cout << endl;
                break;
            case 2:
                cout << "SEARCH Operation -" << endl;
                cout << "Enter VALUE to SEARCH in HEAP: ";
                cin >> insert_value;
                obj.linear_search(insert_value);
                break;
            case 3:
                cout << "DELETE Operation -" << endl;
                cout << "Enter INDEX of Heap Array to DELETE: ";
                cin >> insert_value;
                obj.delete_key(insert_value);
                break;
            case 4:
                cout << "GET Min value : " << obj.get_min();
                cout << endl;
                break;
            case 5:
                cout << "EXTRACT Min value : " << obj.extract_min();
                cout << endl;
                break;
            case 6:
                cout << "HEAP TREE HEIGHT : " << obj.height() << endl;
                break;

            case 7:
                cout << "PRINT Heap Array : " << endl;
                obj.print_heap();

                cout << endl;
                break;

            case 8:
                system("cls");
                break;

            default:
                cout << "Enter Proper Option number " << endl;
        }
    }
    while(option !=0);


    return 0;
}

