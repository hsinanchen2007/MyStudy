### 解题思路
与 739. Daily Temperatures (Medium) 不同的是，数组是循环数组，并且最后要求的不是距离而是下一个元素。

### 代码

```cpp
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> next(n,-1);
        stack<int> pre;
        for(int i = 0;i<n*2;i++)
        {
            int num = nums[i%n];
            while(!pre.empty()&&nums[pre.top()]<num)
            {
                next[pre.top()]=num;
                pre.pop();
            }
            if(i<n)
                pre.push(i);
            
        }
        return next;


    }
};
```