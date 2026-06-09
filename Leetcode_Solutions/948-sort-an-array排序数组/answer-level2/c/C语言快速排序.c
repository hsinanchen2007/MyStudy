### 解题思路
这种题冒泡肯定死掉，干脆用快排，就这样了

### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

void Swap(int arr[], int low, int high)
{
    int temp;
    temp = arr[low];
    arr[low] = arr[high];
    arr[high] = temp;
}
 
int Partition(int arr[], int low, int high)
{
    int base = arr[low];
    while(low < high)
    {
        while(low < high && arr[high] >= base)
        {
            high --;
        }
        Swap(arr, low, high);
        while(low < high && arr[low] <= base)
        {
            low ++;
        }
        Swap(arr, low, high);
    }
    return low;
}
 
int  QuickSort(int arr[], int low, int high)
{
    if(low < high)
    {
        int base = Partition(arr, low, high);
        QuickSort(arr, low, base - 1);
        QuickSort(arr, base + 1, high);
    }
    return arr;
}


int* sortArray(int* nums, int numsSize, int* returnSize){
    QuickSort(nums, 0, numsSize-1);
    *returnSize=numsSize;
    return nums;

}
```