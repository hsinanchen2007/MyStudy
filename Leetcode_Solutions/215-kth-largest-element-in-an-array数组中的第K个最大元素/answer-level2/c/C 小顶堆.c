### 解题思路
此处撰写解题思路

### 代码

```c
void heapSwap(int *a,int*b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void heapSort(int *heap, int heapSize) {
    int dad = 1, son = dad << 1;//左移1位，乘以2.
    while (son <= heapSize) {
        if (son+1 <= heapSize && heap[son+1] < heap[son]) {
            son++;//找出左右子节点中较小的值
        }
        if (heap[dad] > heap[son]) {
            heapSwap(&heap[dad], &heap[son]);//将最小的数上浮
            dad = son;
            son = dad << 1;
        }
        else {
            return;
        }
    }
}
//插入
void heapInsert(int* heap,  int *heapSize,int num) {
    heap[++(*heapSize)] = num;//下标从1开始，下标即heap元素个数//新插入元素放在堆的末尾，作为son。
    int son = *heapSize, dad = son >> 1;// 位移算符>>，左右子节点下标/2，均可得到其父节点
    while (dad) {
        if (heap[son] < heap[dad]) {
            heapSwap(&heap[son], &heap[dad]);//子节点值小，则上浮
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
                heap[1] = nums[i];//替换堆顶
                heapSort(heap,heapsize);//排序
                // printf("\n heap insert %d :  ", nums[i]);
                // for(int i = 1; i <= heapsize; i++){
                //     printf("%d ", heap[i]);
                // }
            }
        }else { //堆未满直接插入
            heapInsert(heap,&heapsize,nums[i]);//排出最小元素-堆顶
            // printf("\n fulfilling heap:");
            //     for(int i = 1; i <= heapsize; i++){
            //         printf("%d ", heap[i]);
            //     }
        }
    }
    return heap[1];
}
```