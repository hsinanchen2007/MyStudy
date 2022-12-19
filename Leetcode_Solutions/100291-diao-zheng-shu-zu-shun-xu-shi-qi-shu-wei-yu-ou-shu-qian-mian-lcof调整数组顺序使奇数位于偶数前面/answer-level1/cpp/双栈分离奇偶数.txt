### 解题思路
将奇数压入栈a,
偶数压入栈b
再合并
### 代码

```cpp
class Solution {
public:
    vector<int> exchange(vector<int>& nums) {
        stack<int> a;
        stack<int> b;
        vector<int> res;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]%2==1)
            a.push(nums[i]);
            else
            b.push(nums[i]);
        }
        static int j=0;
        while(!a.empty())
        {
           res.push_back(a.top());
           a.pop();
        }
        while(!b.empty())
        {
           res.push_back(b.top());
           b.pop();
        }
        return res;
    }
};
```