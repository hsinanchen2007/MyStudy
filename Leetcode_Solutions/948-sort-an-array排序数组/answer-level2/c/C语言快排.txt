### 解题思路
1.定义一个快排函数；
2.调用快排函数，将returnSize的值设置为numsSize，返回排序后的数组

### 代码

```c
void quick_sort(int arr[], int left, int right)
{
        int temp, mid, i, j;
        i = left;
        j = right;
        mid = arr[(left+right)/2];
        while(i<=j)
        {
                while(arr[i]<mid)
                {
                        i++;
                }
                while(arr[j]>mid)
                {
                        j--;
                }
                if(i<=j)
                {
                        temp = arr[i];
                        arr[i] = arr[j];
                        arr[j] = temp;
                        i++;
                        j--;
                }
        }
        if(i<right)
        {
                quick_sort(arr, i ,right);
        }
        if(j>left)
        {
                quick_sort(arr,left,j);
        }
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* sortArray(int* nums, int numsSize, int* returnSize){
    quick_sort(nums, 0, numsSize-1);
    *returnSize = numsSize;
    return nums;
}


```