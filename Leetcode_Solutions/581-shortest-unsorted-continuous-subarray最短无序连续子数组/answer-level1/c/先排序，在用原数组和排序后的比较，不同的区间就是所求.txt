### 解题思路
此处撰写解题思路

### 代码

```c

int* quick_sort(int* a, int left, int right)
{
	if (left < right)
	{
		int max = a[left], l = left, r = right;
		while (l < r)
		{
			while (max <= a[r] && l < r)
				--r;
			if (l < r)
				a[l++] = a[r];
			while (max >= a[l] && l < r)
				++l;
			if (l < r)
				a[r--] = a[l];
		}
		a[l] = max;
		quick_sort(a, left, l - 1);
		quick_sort(a, l + 1, right);
	}
    return a;
}

int findUnsortedSubarray(int* nums, int numsSize)
{
    int ret = 0;
    int *a = (int*)malloc(sizeof(int) * numsSize);   //开空间
    for(int i = 0; i < numsSize; ++i)           //复制一个数组a
        a[i] = nums[i]; 
    a = quick_sort(a,0,numsSize-1);         //给数组a排序
    for(int i = 0,j = numsSize - 1; i < j; ++i,--j) //双头循环往中间走，nums 和 a不同的区间就是需要找的空间
    {
        if(nums[i] != a[i] && nums[j] != a[j])
        {
            ret = j - i + 1;
            break;
        }
        else if(nums[i] != a[i])
            --i;
        else if(nums[j] != a[j])
            ++j;            
    }
    return ret;

}


```