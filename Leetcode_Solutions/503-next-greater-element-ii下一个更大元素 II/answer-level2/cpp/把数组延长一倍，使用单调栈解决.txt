### 解题思路
把数组长度延长一倍，就可以循环到数组内所有元素，使用单调递减栈解决。
### 代码

```cpp
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int len = nums.size(), i = 0;
        for(int j = 0; j < len; j ++)  //数组长度延长一倍
        nums.push_back(nums[j]);
        stack<int> stacks;
        vector<int> ans(2 * len, -1);  //初始化数组全为-1
        while(i < 2 * len)
        {
            if(stacks.size() && nums[stacks.top()] < nums[i])  //单调递减栈，当栈顶元素小于当前元素时，更新答案数组
            {
                ans[stacks.top()] = nums[i];
                stacks.pop();        
            }
            else 
            {
                stacks.push(i);
                i ++;
            }
        }
        vector<int> anss;
        for(int i = 0; i < len; i ++)  //只需要答案数组的一半
        anss.push_back(ans[i]);
        return anss;
    }
};
```