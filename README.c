 #include<stdio.h>
#include<stdlib.h>
#include<conio.h>
struct ArrayHeap *createHeap(int);
void insertData(struct ArrayHeap *);
void heapifyUp(struct ArrayHeap *, int);
void deleteData(struct ArrayHeap *);
void maxData(struct ArrayHeap *);
void minData(struct ArrayHeap *);
void searchData(struct ArrayHeap *, int);
void totalElements(struct ArrayHeap *);
void printHeap(struct ArrayHeap *);
void changeData(struct ArrayHeap *,int);
void checkStatus(struct ArrayHeap *);
void printSortedHeap(struct ArrayHeap *);
void deleteHeap(struct ArrayHeap *);
int menu();
struct ArrayHeap
{
    int *array;
    int top;
    int capacity;
};
struct ArrayHeap *createHeap(int capacity)
{
    struct ArrayHeap *temp;
    temp = (struct ArrayHeap *)malloc(sizeof(struct ArrayHeap));
    if(temp==NULL)
    {
        printf("Memory allocation failed : \n");
        exit(1);
    }
    temp->capacity = capacity;
    temp->top = -1;
    temp->array = (int*)malloc(sizeof(int)*temp->capacity);
    if(temp->array==NULL)
    {
        printf("Memory allocation failed : \n");
        exit(1);
    }
    return temp;
}
void insertData(struct ArrayHeap *heap)
{
    if(heap->top==heap->capacity-1)
    {
        printf("Heap is full : \n");
    }
    else
    {
        int data;
        printf("Enter the data which you want to insert in heap : ");
        scanf("%d",&data);
        heap->top = heap->top+1;
        heap->array[heap->top] = data;
        heapifyUp(heap, heap->top);
    }
}
void heapifyUp(struct ArrayHeap *heap, int index)
{
    int temp;
    int parent = (index-1)/2;
    while(index>0 && heap->array[parent]<heap->array[index])
    {
        temp = heap->array[index];
        heap->array[index] = heap->array[parent];
        heap->array[parent] = temp;
        index = parent;
        parent = (index - 1)/2;
    }
}
void deleteData(struct ArrayHeap *heap)
{
    if(heap->top<0)
    {
        return;
    }
    else
    {
        heap->array[0] = heap->array[heap->top];
        heap->top = heap->top-1;
        int i = 0;
        while(i<=(heap->top)/2)
        {
            int l_c = i*2+1;
            int r_c = i*2+2;
            int child;
            if(r_c<= (heap->top)/2 && heap->array[r_c]>heap->array[l_c])
            {
                child = r_c;
            }
            else
            {
                child = l_c;
            }
            if(heap->array[child]>heap->array[i])
            {
                int temp = heap->array[i];
                heap->array[i] = heap->array[child];
                heap->array[child] = temp;
                i = child;
            }
            else
            {
                break;
            }
        }
    }
}
void maxData(struct ArrayHeap *heap)
{
    int data;
    data = heap->array[0];
    printf("Maximum data in heap : %d \n",data);
}
void minData(struct ArrayHeap *heap)
{
    int data;
    data = heap->array[0];
    int i;
    for(i=1;i<=heap->top;i++)
    {
        if(heap->array[i]<data)
        {
            data = heap->array[i];
        }
    }
    printf("Minimum data in heap : %d \n",data);
}
void searchData(struct ArrayHeap *heap, int data)
{
    int i;
    for(i=0;i<=heap->top;i++)
    {
        if(data==heap->array[i])
        {
            printf("Data %d found in heap at index %d: \n",data,i);
            return;
        }
    }
    printf("Data %d not found in heap : \n",data);
}
void totalElements(struct ArrayHeap *heap)
{
    printf("Size of heap : %d \n",heap->top+1);
}
void printHeap(struct ArrayHeap *heap)
{
    if(heap->top<0)
    {
        printf("Heap is empty.\n");
        return;
    }
    printf("Heap elements: ");
    int i;
    for(i=0;i<=heap->top;i++)
    {
        printf("%d ", heap->array[i]);
    }
    printf("\n");
}
void changeData(struct ArrayHeap *heap,int data)
{
    int i, newData;
    printf("Enter new data which you want to insert in place old data : ");
    scanf("%d",&newData);
    for(i=0;i<=heap->top;i++)
    {
        if(data==heap->array[i])
        {
            heap->array[i] = newData;
            heapifyUp(heap,i);
            return;
        }
    }
}
void checkStatus(struct ArrayHeap *heap)
{
    if(heap->top==heap->capacity-1)
    {
        printf("Heap is full : \n");
        return;
    }
    else
    {
        printf("Heap is not full : \n");
    }
}
void deleteHeap(struct ArrayHeap *heap)
{
    free(heap->array);
    free(heap);
}
void printSortedHeap(struct ArrayHeap *heap)
{
    int i;
    int *sort = (int *)malloc(sizeof(int)*heap->top+1);
    if(sort==NULL)
    {
        printf("Memory allocation failed : \n");
        exit(1);
    }
    for(i=0;i<=heap->top;i++)
    {
        sort[i] = heap->array[i];
    }
    int size, round, temp;
    size = heap->top;
    for(round=0;round<=size-1;round++)
    {
        for(i=0;i<=size-1-round;i++)
        {
            if(sort[i]>sort[i+1])
            {
                temp = sort[i];
                sort[i] = sort[i+1];
                sort[i+1] = temp;
            }
        }
    }
    printf("Sorted Heap : ");
    for (i=0;i<=size;i++)
    {
        printf("%d  ",sort[i]);
    }
    printf("\n");
    free(sort);
}
int menu()
{
    int choice;
    printf("    Enter your choice : \n");
    printf(" 1. Create Heap : \n");
    printf(" 2. Insert data in heap : \n");
    printf(" 3. Delete data from heap : \n");
    printf(" 4. Maximum data from heap : \n");
    printf(" 5. Minimum data from heap : \n");
    printf(" 6. Search data in the heap : \n");
    printf(" 7. Size of heap : \n");
    printf(" 8. Print heap : \n");
    printf(" 9. Change data from heap : \n");
    printf("10. Heap is empty or not : \n");
    printf("11. Print sorted heap : \n");
    printf("12. Delete heap : \n");
    printf("13. Exit : \n");
    printf("    Your choice : ");
    scanf("%d",&choice);
    return(choice);
}
int main()
{
    struct ArrayHeap *heap = NULL;
    while(1)
    {
        switch(menu())
        {
            case 1:
                if(heap==NULL)
                {
                    int size;
                    printf("Enter the size of heap : ");
                    scanf("%d",&size);
                    heap = createHeap(size);
                }
                else
                {
                    printf("Heap is already created : \n");
                }
                break;
            case 2:
                if(heap!=NULL)
                {
                    insertData(heap);
                }
                else
                {
                    printf("Create heap  first : \n");
                }
                break;
            case 3:
                if(heap!=NULL)
                {
                    deleteData(heap);
                }
                else
                {
                    printf("Create heap first : \n");
                }
                break;
            case 4:
                if(heap!=NULL)
                {
                    maxData(heap);
                }
                else
                {
                    printf("Create heap first : \n");
                }
                break;
            case 5:
                if(heap!=NULL)
                {
                    minData(heap);
                }
                else
                {
                    printf("Create heap first : \n");
                }
                break;
            case 6:
               if(heap!=NULL)
                {
                    int data;
                    printf("Enter the data to search in heap: ");
                    scanf("%d", &data);
                    searchData(heap, data);
                }
               else
                {
                    printf("Create a heap first.\n");
                }
                break;
            case 7:
                if(heap!=NULL)
                {
                    totalElements(heap);
                }
                else
                {
                    printf("Heap is empty.\n");
                }
                break;
            case 8:
                if(heap!=NULL)
                {
                    printHeap(heap);
                }
                else
                {
                    printf("Create heap first : \n");
                }
                break;
            case 9:
                if(heap!=NULL)
                {
                    int data;
                    printf("Enter the data which you want to change in heap : ");
                    scanf("%d",&data);
                    changeData(heap,data);
                }
                else
                {
                    printf("Create heap first : \n");
                }
                break;
            case 10:
                if(heap!=NULL)
                {
                   checkStatus(heap);
                }
                else
                {
                    printf("Create heap first : \n");
                }
                break;
            case 11:
                if(heap!=NULL)
                {
                    printSortedHeap(heap);
                }
                else
                {
                    printf("Create heap first : \n");
                }
                break;
            case 12:
                if(heap!=NULL)
                {
                    deleteHeap(heap);
                    heap = NULL;
                }
                else
                {
                    printf("Create heap first : \n");
                }
                break;
            case 13:
                exit(0);
            default:
                printf("Invalid choice : \n");
        }
    }
    return 0;
}

