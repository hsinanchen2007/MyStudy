### 解题思路
1. 直接哈希
2. 用大小26的数组表示哈希表(题目说不用额外数据结构, 不知道这样算不算数据结构?)
3. 排序后直接可以判断重复字母

### 代码

```cpp
class Solution {
public:
    bool isUnique(string astr) {
        sort(astr.begin(), astr.end());
        for (int i = 1; i < astr.size(); ++i) {
            if (astr[i - 1] == astr[i]) return false;
        }
        return true;
    }
};
```