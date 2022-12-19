### 解题思路
此处撰写解题思路

### 代码

```c
void QuickSort(int* nums, int left, int right)  
{
        if (left < right)
        {
               int x = nums[left], l = left, r = right;
               while (l < r)
               {
                       while(l < r && x <= nums[r])                   
                              --r;
                       if (l < r)               
                              nums[l++] = nums[r];
                       while (l < r && x >= nums[l])   
                              ++l;
                       if (l < r)
                       nums[r] = nums[l];      
               }
               nums[l] = x;
               QuickSort(nums, left, l - 1);     
               QuickSort(nums, l + 1, right);
        }
}
int minIncrementForUnique(int* A, int ASize)
{
    QuickSort(A,0,ASize-1);   //排序
    int num = 0;
    if(ASize == 0)
        return 0;
    for(int i = 1; i < ASize; ++i)
    {
        if(A[i] <= A[i - 1])    //不能是等于，否则 1 2 2 2-> 1 2 3 2  时 3 不等于 2 则后面得都不会便，所以是 <= 
        {
            int tmp = abs(A[i] - A[i-1]) + 1;    加它们绝对值在加1
            A[i] += tmp;
            num += tmp;
        }
    }
    return num;
}
```