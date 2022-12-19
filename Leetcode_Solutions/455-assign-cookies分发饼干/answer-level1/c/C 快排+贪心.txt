![Snipaste_2020-03-13_19-54-41.jpg](https://pic.leetcode-cn.com/6593b157c7f7f2a61081d01fb98307f73d694070aca0ff57fc1251a96a01e8c1-Snipaste_2020-03-13_19-54-41.jpg)

### 解题思路
对两个数组分别快速排序，然后逐个比较

### 代码

```c


int findContentChildren(int* g, int gSize, int* s, int sSize){
    int i = 0, j = 0;
    quickSort(g, 0, gSize-1);
    quickSort(s, 0, sSize-1);
    while(i < gSize && j < sSize)
    {
        if(s[j] >= g[i])//满足了当前孩子，指向下一个孩子
            i++;
        j++;//是否满足都要指向下一个饼干
    }
    return i;
}

void quickSort(int* nums, int low, int high)
{
    if(low < high)
    {
        int pivot_loc = partition(nums, low, high);
        quickSort(nums, low, pivot_loc-1);
        quickSort(nums, pivot_loc+1, high);
    }
}

int partition(int* nums, int low, int high)
{
    int pivot = nums[low];
    while(low < high)
    {
        while(low < high && nums[high] >= pivot)
            high--;
        nums[low] = nums[high];
        while(low < high && nums[low] <= pivot)
            low++;
        nums[high] = nums[low];
    }
    nums[low] = pivot;
    return low;
}

```