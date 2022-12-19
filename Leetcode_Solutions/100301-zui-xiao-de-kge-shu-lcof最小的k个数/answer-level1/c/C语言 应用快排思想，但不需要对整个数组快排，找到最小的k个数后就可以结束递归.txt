思路：
    利用快排思想，实现Partition()函数，当Partition()返回的索引值刚好等于k时，结束递归。
代码：
void Swap(int *arr, int p, int q)
{
    int tmp;
    
    if (p == q) {
        return;
    }

    tmp = arr[p];
    arr[p] = arr[q];
    arr[q] = tmp;

    return;
}

int Partition(int *arr, int left, int right)
{
    int i, j;
    int tmp;

    tmp = arr[right];
    
    i = left - 1;
    for (j = left; j < right; j++) {
        if (arr[j] < tmp) {
            i++;
            Swap(arr, i, j);
        }
    }
    Swap(arr, i+1, j);

    return i + 1;
}

int Found(int *arr, int left, int right, int k)
{
    int index = 0;

    index = Partition(arr, left, right);
    if (index > k) {
        return Found(arr, left, index - 1, k);
    } else if (index < k) {
        return Found(arr, index + 1, right, k);
    }

    return index;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* getLeastNumbers(int* arr, int arrSize, int k, int* returnSize){
    *returnSize = k;

    if (k >= arrSize) {
        *returnSize = arrSize;
        return arr;
    }
    Found(arr, 0, arrSize - 1, k);

    return arr;
}