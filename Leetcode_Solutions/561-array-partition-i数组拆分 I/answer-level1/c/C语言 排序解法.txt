### 解题思路
快排后遍历数组，将偶数位的数据相加即为返回值

### 代码

```c

void swap(int* arr, int low, int high)
{
    int temp;
    temp = arr[low];
    arr[low] = arr[high];
    arr[high] = temp;
}

int Partition(int* array, int low, int high){
    int base = array[low];
    while(low < high){
        while(low < high && array[high] >= base){
            high --;
        }
        swap(array,low,high);//array[low] = array[high];
        while(low < high && array[low] <= base){
            low ++;
        }
        swap(array,low,high);//array[high] = array[low];
    }
    array[low] = base;
    return low;
}
void QuickSort(int* array, int low, int high){
    if(low < high){
        int base = Partition(array,low,high);
        QuickSort(array,low,base - 1);
        QuickSort(array, base + 1, high);
    }
}

int arrayPairSum(int* nums, int numsSize){
    int count = 0;
    int i;
    QuickSort(nums,0,numsSize-1);
    for(i=0;i<numsSize;i = i+2)
    {
        count += nums[i];
    }
    return count;
}
```