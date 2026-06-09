![0775d84f7b8f4dca82b3e16494c40da79d3c421f4d7fd6394420fba4c79d218b-image.png](https://pic.leetcode-cn.com/4cf5178b19b5e8d28e7205b8ffaed8367b25cacc7bded6cfca28e7a7f394566b-0775d84f7b8f4dca82b3e16494c40da79d3c421f4d7fd6394420fba4c79d218b-image.png)

### 解题思路
[215. 数组中的第K个最大元素](https://leetcode-cn.com/problems/kth-largest-element-in-an-array/)
代码照搬过来了，小顶堆->大顶堆
但是耗时还是挺多的
### 代码

```c
//升序排序后的第k个元素
void heapSwap(int *a,int*b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void heapSort(int *heap, int heapSize) {
    int dad = 1, son = dad << 1;
    while (son <= heapSize) {
        if (son+1 <= heapSize && heap[son+1] > heap[son]) {
            son++;
        }
        if (heap[dad] < heap[son]) {
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
        if (heap[son] > heap[dad]) {
            heapSwap(&heap[son], &heap[dad]);
            son = dad;
            dad = son >> 1;
        }
        else {
            return;
        }
    }
}
int kthSmallest(int** matrix, int matrixSize, int* matrixColSize, int k){
    int *heap = (int *)malloc((k+1) * sizeof(int));
    int heapsize = 0;
    for(int i = 0; i < matrixSize; i++){
        for (int j = 0; j < *matrixColSize; j++){
            if (heapsize == k) {
                if(matrix[i][j] < heap[1]){ 
                    heap[1] = matrix[i][j];//替换堆顶
                    heapSort(heap,heapsize);//排序
                }
            }else { //堆未满直接插入
                heapInsert(heap,&heapsize,matrix[i][j]);
                }         
        }
    }
    return heap[1];
}

```