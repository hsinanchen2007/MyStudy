```
1、始终选择最小的两个数字；
2、每次选出来的数字计算下费用；
3、计算弹出来的两个数字之和以后插回到队列；
4、直到队列只剩下最后一个数据停止；

int g_head = 0;
int g_tail = 0;
struct HEAP{
    int index;
    int *data;
};
struct HEAP *g_heap = NULL;
void Swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
    return;
}
void AdjustUp(int childIndex)
{
    int child = childIndex;
    int parent = (child - 1) / 2;
    while(child > 0) {
        if(g_heap->data[child] < g_heap->data[parent] ) {
            Swap(&g_heap->data[child], &g_heap->data[parent]);
        }else{
            break;
        }
        child = parent;
        parent = (child - 1) / 2;
    }
    return;
}

void AdjustDown(int parentIndex)
{
    int parent = parentIndex;
    int child =  2 * parent + 1;
    while (child < g_heap->index) {
        if(child + 1 < g_heap->index && g_heap->data[child] > g_heap->data[child + 1] ) {
            child = child + 1;
        }
        if(g_heap->data[child] < g_heap->data[parent] ) {
            Swap(&g_heap->data[child],&g_heap->data[parent]);
        }else{
            break;
        }
        parent = child;
        child =  2 * parent + 1;
    }
    return;
}

void AddQue(int id) 
{
    int index = g_heap->index;
    g_heap->data[index] = id;
    AdjustUp(index);
    g_heap->index++;
    g_tail++;
    return;
}

void DelQue(int *id) 
{
    *id = g_heap->data[0];
    g_heap->index--;
    int index = g_heap->index;
    Swap(&g_heap->data[0], &g_heap->data[index]);
    AdjustDown(0);
    g_head++;
    return;
}

int GetNum()
{
    return g_tail - g_head;
}

int connectSticks(int* sticks, int sticksSize){
    int total = 0;
    g_head = 0;
    g_tail = 0;
    g_heap = malloc(sizeof(struct HEAP));
    g_heap->index = 0;
    g_heap->data = malloc(sizeof(int) * sticksSize * 2);
    for(int i = 0 ; i < sticksSize; i++) {
        AddQue(sticks[i]);
    }
    while (GetNum() > 1) {
        int num1,num2;
        DelQue(&num1); 
        DelQue(&num2); 
        int temp = num1 + num2;
        total += temp;
        AddQue(temp);
    }
    free(g_heap->data);
    free(g_heap);
    return total;
}
```
