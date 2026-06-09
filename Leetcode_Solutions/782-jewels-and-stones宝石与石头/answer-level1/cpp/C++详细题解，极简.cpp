### 题目解释
一种字母就是一种石头（一个字母的大小写当作不同石头）
### 思路
把宝石类型J记录进set中，用count函数一块块鉴定所拥有的石头是否属于set内的任意一个。若是，ans加一。
```cpp
class Solution {
public:
    int numJewelsInStones(string J, string S) {
        int ans = 0;
        unordered_set<char> jew;
        for(auto i : J) jew.insert(i); //记录宝石类型
        for(auto s : S) if(jew.count(s))    ++ ans; //若拥有的石头里有宝石，答案加一
        return ans;
    }
};
```
