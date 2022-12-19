### 解题思路
从数组最大长度开始，找到最大值，先翻转到最前面，再二次反转到最后面，这样就把一个最大值排好了。
不断缩小数组长度，直到有序为止！
可以证明，最大反转次数不超过2*A.length。

### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#define MAX(a, b) (a > b ? a : b)
bool isseq(int* arr, int k); //判断数组前k个元素是否有序（从1开始）
int maxarr(int* arr, int k); //返回数组前k个元素中的最大值的所在位置（从1开始）
void printarr(int* arr, int arrSize); //打印数组所有元素
void adjust(int* arr, int k, int j); //将数组前k个元素中的第j个元素通过反转调整到第k个位置（从1开始）

int* pancakeSort(int* A, int ASize, int* returnSize){
    int* C;
    C = (int *)malloc(sizeof(int) * ASize * 2);
    if( isseq(A, ASize) ){
        *returnSize = 0;
        return C;
    }

    int* B;
    B = (int *)malloc(sizeof(int) * ASize);
    int i, j=0, k;
    for(i=0; i<ASize; i++)
        B[i] = A[i];
    
    while( ! isseq(B, i) ){
        k = maxarr(B, i);
        if( k != 1 )
            C[j++] = k;
        C[j++] = i;
        adjust(B, i, k);
        i--;
    }

    *returnSize = j;
    return C;
}

bool isseq(int* arr, int k){
    if(k < 2)
        return true;
    int i;
    for(i=0; i<k-1; i++)
        if(arr[i] > arr[i+1])
            return false;
    return true;
}

int maxarr(int* arr, int k){
    int i;
    for(i=0; i<k; i++)
        if(arr[i] == k)
            break;
    return i+1;
}

void printarr(int* arr, int arrSize){
    int i;
    for(i=0; i<arrSize; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

void adjust(int* arr, int k, int j){
    int i, temp;
    if(j != 0){
        for(i=0; i<j/2; i++){
            temp = arr[i];
            arr[i] = arr[j-i-1];
            arr[j-i-1] = temp;
        }
    }
    for(i=0; i<k/2; i++){
        temp = arr[i];
        arr[i] = arr[k-i-1];
        arr[k-i-1] = temp;
    }
}

```