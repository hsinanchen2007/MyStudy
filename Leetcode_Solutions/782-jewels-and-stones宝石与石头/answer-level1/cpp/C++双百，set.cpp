### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int numJewelsInStones(string J, string S) {
        unordered_set<char> m;
        int ans=0;
        for(char c:J)m.insert(c);
        for(char c:S)if(m.find(c)!=m.end())ans++;
        return ans;
    }
};
```