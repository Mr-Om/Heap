#include<bits/stdc++.h>
using namespace std;


class Heap{
    vector<int> heap;
    int minHeap;
public:

    //Constructor
    Heap(bool type=true)
    {
        heap.push_back(-1);
        minHeap = type;
    }

    bool compare (int a, int b)
    {
        //If the heap type is minHeap the return true for child in smaller than parent.
        if(minHeap)
            return a<b;
        //If the heap type is maxHeap the return true for child in greater than parent.
        else
            return a>b;
    }

    void insert(int node)
    {
        heap.push_back(node);
        int index = heap.size()-1;
        int parent = index/2;

        // While inserted node is not at the 1st position and value of the node is smaller than its parent
        while(index > 1 && compare(heap[index],heap[parent]))
        {
            //Swapping parent with child

            swap(heap[index],heap[parent]);
            index = parent;
            parent = index/2;
        
        }
    }

    bool isEmpty()
    {
        return heap.size()==1;
    }

    int top()
    {
        return heap[1];
    }
    
};

int main()
{
    Heap heap;
    heap.insert(23);
    heap.insert(18);
    heap.insert(14);
    heap.insert(17);
    heap.insert(10);
    heap.insert(56);
    heap.insert(5);
    cout<<heap.top();
}