#include <iostream>

/*
 * Priority queue using a heap as the way to determine priorities
 */
class PriorityQueue
{
    int size = 0;
    const int MAXSIZE = 10;
    int values[11];
    
    //
    // method to bring the smallest value to the top of the heap when it is added
    //
    void percolateUp();
    
    //
    // method to move the small values up after the first value has been removed
    //
    void percolateDown();
    
    void swap(int ind1, int ind2);
    
public:
    
    PriorityQueue();
    
    //
    // method that goes through each subnodes of the parent node, and determines
    // where to add the integer
    // @param value : the integer to be inserted into the queue
    //
    void push(int value);
    
    //
    // method that dequeues the minimum value in the priority queue
    // @return : minimum value in the priority queue
    //
    int pop();
};

PriorityQueue::PriorityQueue()
{
    values[0] = 0;
}

void PriorityQueue::percolateUp()
{
    int childInd = size;        //child index
    int parentInd = size / 2;   //parent index
    while(values[childInd] < values[parentInd])
    {
        swap(childInd, parentInd);
        childInd = parentInd;
        parentInd /= 2;
    }
}

void PriorityQueue::percolateDown()
{
    int childInd = 1;
    while (childInd <= size)
    {
        int parentInd = childInd;
        childInd *= 2;
        if(values[childInd] >= values[childInd + 1])
        {
            childInd++;
        }
        values[parentInd] = values[childInd];
    }
}

void PriorityQueue::swap(int ind1, int ind2)
{
    int temp = values[ind1];
    values[ind1] = values[ind2];
    values[ind2] = temp;
}

void PriorityQueue::push(int value)
{
    if(size <= MAXSIZE)
    {
        size++;
        values[size] = value;
        percolateUp();
    }
}

int PriorityQueue::pop()
{
    int value = values[1];
    percolateDown();
    if(size > 0)
    {
        values[size] = INT_MAX;
        size--;
    }
    return value;
}

int main()
{
    PriorityQueue p1;
    p1.push(5);
    p1.push(3);
    p1.push(6);
    p1.push(10);
    p1.push(4);
    p1.push(1);
    p1.push(2);
    std::cout << p1.pop() << std::endl;
    std::cout << p1.pop() << std::endl;
    std::cout << p1.pop() << std::endl;
    std::cout << p1.pop() << std::endl;
    std::cout << p1.pop() << std::endl;
    std::cout << p1.pop() << std::endl;
    return 0;
}
