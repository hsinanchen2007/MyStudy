### 解题思路
1. 此处的单调栈是递减栈。
2. 循环数组遍历的方法：遍历两次，遍历时的下标通过求模获得！
for(int i=0 ; i<nums.size()*2 ; i++)
{
    int j = i % nums.size() ;
}


### 代码

```cpp
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {

        vector<int> res(nums.size() , -1) ;

        if(nums.empty()) return res ;

        stack<pair<int ,int>> stk ;

        for(int i=0 ; i<nums.size()*2 ; i++)
        {
            int j = i % nums.size() ;

            while(!stk.empty() && stk.top().second < nums[j])
            {
                res[stk.top().first] = nums[j] ;
                stk.pop();
            }

            stk.push({j , nums[j]}) ;
        }

        return res ;
    }
};
```