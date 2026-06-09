### 解题思路
不明白为什么空间复杂度O（1）的算法跟空间复杂度O（n／2）的算法是一样的，只能表明n很小。

### 代码

```cpp
class Solution {
public:
    // int majorityElement(vector<int>& nums) {
    //     unordered_map<int,int> mp;
    //     int target = nums.size() / 2;
    //     for (int v : nums) {
    //         if (++mp[v] > target) return v;
    //     }
    //     return -1;

    // }
     int majorityElement(vector<int>& nums) {
         int cond = -1, cnt = 0;
         for (int v : nums) {
             if (v == cond) {
                 ++cnt;
             }
             else if (--cnt<0) {
                 cond = v;
                 cnt = 1;
             }
         }
         return cond;
     }
};
```