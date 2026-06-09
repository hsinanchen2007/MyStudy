### 解题思路
直接调用set的拷贝构造，把vector全部的值赋给set，直接比较size()大小。
这个速度比较慢，我去想想别的办法。
纯属娱乐，别说我玩赖！！！

### 代码

```cpp
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> se(nums.begin(),nums.end());
        return se.size()!=nums.size();
    }
};
```