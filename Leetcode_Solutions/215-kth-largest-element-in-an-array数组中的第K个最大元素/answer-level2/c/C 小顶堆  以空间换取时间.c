![0775d84f7b8f4dca82b3e16494c40da79d3c421f4d7fd6394420fba4c79d218b-image.png](https://pic.leetcode-cn.com/9fac9176322ad686ef794ec0e6328858c10a3d377bce286f22fbb7a794b456a8-0775d84f7b8f4dca82b3e16494c40da79d3c421f4d7fd6394420fba4c79d218b-image.png)

### 解题思路
heap的insert插入只保证了堆顶元素的最小性质，不对堆内元素进行排序，
所以，关键的是需要heapsort函数，以保证堆内元素的顺序性。

### 代码

```c
void heapSwap(int *a,int*b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void heapSort(int *heap, int heapSize) {
    int dad = 1, son = dad << 1;
    while (son <= heapSize) {
        if (son+1 <= heapSize && heap[son+1] < heap[son]) {
            son++;
        }
        if (heap[dad] > heap[son]) {
            heapSwap(&heap[dad], &heap[son]);
            dad = son;
            son = dad << 1;
        }
        else {
            return;
        }
    }
}
void heapInsert(int* heap,  int *heapSize,int num) {
    heap[++(*heapSize)] = num;
    int son = *heapSize, dad = son >> 1;
    while (dad) {
        if (heap[son] < heap[dad]) {
            heapSwap(&heap[son], &heap[dad]);
            son = dad;
            dad = son >> 1;
        }
        else {
            return;
        }
    }
}

int findKthLargest(int* nums, int numsSize, int k) {
    int *heap = malloc(sizeof(int *)*(k+1)); //分配堆空间
    int heapsize = 0;
    for (int i=0;i<numsSize;i++){
        if (heapsize == k) { //堆满情况
            if(nums[i] > heap[1]){ //比堆顶最大元素大时进行插入
                heap[1] = nums[i];
                heapSort(heap,heapsize);
            }
        }else { //堆未满直接插入
            heapInsert(heap,&heapsize,nums[i]);
        }
    }
    return heap[1];
}
```