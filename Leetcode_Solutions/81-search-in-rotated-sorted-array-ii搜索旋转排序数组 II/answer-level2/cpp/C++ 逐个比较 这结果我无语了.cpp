### 解题思路
emmm 
![捕获.PNG](https://pic.leetcode-cn.com/c69416f52de02bcda40526bb9af1aab7ef1e3787dc58fc43069e6746097ef82c-%E6%8D%95%E8%8E%B7.PNG)

### 代码

```cpp
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        //直接比较
        bool ans = false;
        if(nums.empty())
            return ans;

        for(auto c : nums)
        {
            if(c == target)
                return true;
        }

        return ans;
    }
};
```