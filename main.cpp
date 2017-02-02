#include <iostream>
#include <time.h>
#include <stdlib.h>

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
    
    //
    // method that prints all of the elements in the queue
    //
    void print();
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
    int parentInd = 1;
    int childInd = parentInd * 2;
    values[parentInd] = values[size + 1];
    while (childInd + 1 <= size)
    {
        if(values[childInd] > values[childInd + 1])
        {
            childInd++;
        }
        if(values[childInd] < values[parentInd])
        {
            swap(childInd, parentInd);
        }
        parentInd = childInd;
        childInd *= 2;
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
    if(size > 0)
    {
        size--;
    }
    percolateDown();
    return value;
}

void PriorityQueue::print()
{
    for(int i = 1; i < size + 1; i++)
    {
        std::cout << values[i] << " ";
    }
}

int getRand()
{
    return rand() % 100 + 1;
}

int main()
{
    PriorityQueue p1;
    
    // Randomize the seed for rand()
    srand(time(NULL));
    
    // Add the ten numbers
    for(int i = 0; i < 10; i++)
    {
        p1.push(getRand());
    }
    
    // Apply actions and print
    for(int i = 0; i < 30; i++)
    {
        int toAdd = getRand();
        int min = p1.pop();
        std::cout << "The current dispatched number is " << min << std::endl;
        std::cout << "The new coming number is " << toAdd << std::endl;
        p1.push(toAdd);
        std::cout << "The numbers in the queue are ";
        p1.print();
        std::cout << std::endl << std::endl;
    }
    return 0;
}
