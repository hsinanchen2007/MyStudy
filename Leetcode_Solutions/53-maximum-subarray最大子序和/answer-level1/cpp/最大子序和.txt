### 解题思路
手动模拟最大子序和发现，前n项子序和最大值等于  前n-1项最大子序和加第n项的值 与第n项值比较两者间的较大值  然后找出是在整个子序列的最大值

### 代码
执行结果：通过显示详情
执行用时 :4 ms, 在所有 C++ 提交中击败了98.40%的用户
内存消耗 :9.2 MB, 在所有 C++ 提交中击败了71.74%的用户
```cpp
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
       /*int *a;
	    a = (int *)malloc(sizeof(int)*nums.size());
        a[0]=nums[0];
	    int sum =nums[0];
	    for (int i = 1; i < nums.size(); i++)//动态规划法
	    {
	    	a[i]= max(nums[i] + a[i - 1], nums[i]);//记录每个第n个数字前的最大值
		    if (sum < a[i])//存最值
			sum = a[i];
	    }
	    return sum;*/
        int i;
	    int best = nums[0];
	    int sum = nums[0];
	    for (i = 1; i < nums.size(); i++)
	    {
	    	best += nums[i];//best 记录前面最优解    best 与遍历到的值相加，如果值增加，best 存了改变后的那个值
	    	if (best <nums[i])//
	    		best = nums[i];//如果小于，则令最优为当前那个值
	    	if (best >sum)
	    		sum = best;
	    }
	    return sum;
    }
};
```