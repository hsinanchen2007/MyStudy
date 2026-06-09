### 解题思路
中心思路跟官解是一样的
自己理解写了一遍

[@sinclairwang](/u/sinclairwang/) 感谢C++的答案。


### 代码
```python [group1-Python]
class Solution:
    def firstMissingPositive(self, nums: List[int]) -> int:
        # 保证有1
        if 1 not in nums:
            return 1
        
        n = len(nums)
        
        # 保证都在1~n的范围内
        for i in range(n):
            if nums[i] <= 0 or nums[i] > n:
                nums[i] = 1
        
        # 以自身正负为bitmap，标记
        for i in range(n):
            if nums[abs(nums[i])-1] > 0:
                nums[abs(nums[i])-1] = -nums[abs(nums[i])-1]
        
        # 找到第一个为正的索引，即没有出现的最小正数
        for i in range(n):
            if nums[i] > 0:
                return i+1
        
        # 全为负
        return n+1


```
```cpp [group1-cpp]
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size(),f=0;
        for(int i=0;i<n;i++)
            if(nums[i]==1) 
                f=1;break;
        if(!f)  return 1;
        for(int i=0;i<n;i++){
            if(nums[i]<=0||nums[i]>n)
                nums[i] = 1;
        }
        for(int i=0;i<n;i++)
            nums[abs(nums[i])-1] = -abs(nums[abs(nums[i])-1]);
        for(int i=0;i<n;i++)
            if(nums[i]>0) return i+1;
        return n+1;
 
    }
};


```