### 解题思路
执行用时 :20 ms, 在所有 C++ 提交中击败了45.02%的用户
### 代码

```cpp
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int a = 0;
        for(auto num: nums){
            a = a ^ num;
        }
        return a;
    }
};
```