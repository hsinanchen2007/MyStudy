### 解题思路
第一种方法可以通过所有测试。可以看做好几个不同军队抢夺一个高地，他们一对一消耗
因为有个军队超过了n/2，经过消耗后，他还有人活着。
第二种方法，先快速排序，复杂nlogn，因为有个元素过半,所以选取nums[n/2]。
第二种方法自然笨了很多，有两个用例超时，但毕竟是自己想出来的，还是写上吧，希望大家批评。
### 代码

```c
int majorityElement(int* nums, int numsSize){
    int key = nums[0];
    int count = 0;
    for (size_t i = 0; i < numsSize; i++)
    {
        if(nums[i] == key)
            count++;
        else
            count--;
        
        if(count <= 0)
        {
            key = nums[i+1];
        }
        
    }
    return key;
}
//第二种方法
/*int partition(int *a,int low,int high){
    int pivot=a[low];
    while(low<high){
        while(low<high&&a[high]>=pivot)high--;
        a[low]=a[high];
        while(low<high&&a[low]<=pivot)low++;
        a[high]=a[low];
    }
    a[low]=pivot;
    return low;
}
void quickSort(int *a,int low,int high){
    if(low<high){
        int pivotpos=partition(a,low,high);
        quickSort(a,low,pivotpos-1);
        quickSort(a,pivotpos+1,high);
    }
}
int majorityElement(int* nums, int numsSize){
    quickSort(nums,0,numsSize-1);
    return nums[numsSize/2];
}*/
```