## 思路
### 代码
```
class Solution {
public:
    int numJewelsInStones(string J, string S) {
        unordered_set<char> uset;
        for (char c : J) {
            uset.insert(c);
        }
        int num = 0;
        for (char c : S) {
            if (uset.count(c) > 0) ++num;
        }
        return num;
    }
};
```
