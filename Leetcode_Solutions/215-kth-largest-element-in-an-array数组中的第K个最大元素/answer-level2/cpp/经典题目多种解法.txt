### 解题思路
1.方法一：基于partition的思想

```
void quick_sort(int a[], int left, int right)
{
    if(left >= right)
    {
        return;
    }    
    int index = partition(a,left,right);
    quick_sort(a, left, index - 1);
    quick_sort(a, index + 1, right);                     
}
```


2.优先队列的思想

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> q;
        for(int i=0;i<nums.size();i++)
        {
            if(i < k)
            {
                q.push(nums[i]);
            }
            else if(nums[i] > q.top())
            {
                q.pop();
                q.push(nums[i]);
            }
        }
        return q.top();
    }
};


### 代码

```cpp
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
        if(k < 1 || n < k)
            return INT_MIN;
        int start = 0;
        int end = n - 1;
        
        int index = partition(nums,start, end);
        //循环前循环用到的变量进行的变量初始值操作
        while(index != k-1)
        {
            if(index > k-1)
            {
                end = index-1;
                index = partition(nums,start, end);
            }
            else
            {
                start = index + 1;
                index = partition(nums,start, end);
            }
        }
        return nums[k-1];

    }

  int partition(vector<int>& a, int left, int right)
    {
        int i = left;
        int j = right;
        int pivot = a[left];
        while(i < j)                              
        {  
            //注意：根据本题的题意，我们需要降序排序，所以这里需要修改为<=
            while(i < j && a[j] <= pivot)
            {
                j--;
            }
            if(i < j)
			{
				a[i++] = a[j];
			}
            //注意：根据本题的题意，我们需要降序排序，所以这里需要修改为>=
            while(i < j && a[i] >= pivot)
            {
                i++;
            }
            if(i < j)
			{
				a[j--] = a[i];
			}
        }   
        a[i] = pivot;//根据算法的流程，跳出循环时i==j
        return i;
    }
};
```