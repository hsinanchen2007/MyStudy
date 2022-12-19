### 解题思路
此处撰写解题思路
用堆维护最小的k个数组，有更小的就把数组里delete最大的，然后把小的加到堆里。

最终将堆的size和堆的数据返回。
### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

struct HeapNode{
    int size;
    int idx;
    int *data;
};

typedef struct HeapNode * Heap;

Heap CreateHeap(int size)
{
    Heap h = malloc(sizeof(struct HeapNode));
    h->size = size;
    h->idx = 0;
    h->data = malloc(sizeof(int)*(size+1));
    memset(h->data, 0, sizeof(int)*(size+1));
    h->data[0]= INT_MAX;
    return h;
}

#define child(i) (i*2)

void Insert(Heap h, int num)
{
    int i;
    for(i = ++h->idx; h->data[i/2] < num; i=i/2)
    {
        h->data[i] = h->data[i/2];
    }
    h->data[i] = num;
    return;
}

int Delete(Heap h)
{
    int max = h->data[1];
    int last = h->data[h->idx--];
    int son=0;
    int i;
    for(i=1; i*2 <= h->size ; i=son)
    {
        son =i*2;
        if((son+1 <= h->size) && (h->data[son+1] > h->data[son]))
        {
            son ++;
        }
        if(last < h->data[son])
            h->data[i] = h->data[son];
        else
            break;
    }
    h->data[i] = last;
    return max;
}



int* getLeastNumbers(int* arr, int arrSize, int k, int* returnSize){
    int tmp,index;
    if(arrSize <= k || k==0){
        *returnSize = k;
        return arr;
    }
    Heap h = CreateHeap(k);

    for(int i=0; i<arrSize; i++)
    {
        if(i<k)
            Insert(h, arr[i]);
        else if(arr[i] < h->data[1])
        {
            Delete(h);
            Insert(h, arr[i]);
        }
    } 
    *returnSize = h->size;
    return h->data+1;
}
```