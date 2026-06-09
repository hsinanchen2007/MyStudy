### 解题思路


### 代码

```cpp
class Solution {
public:
    int numJewelsInStones(string J, string S) {
        unordered_map<char,bool> map;
        for(int i = 0;i < J.size();i++)
            map[J[i]] = true;
        int cnt = 0;
        for(int j = 0;j < S.size();j++)
            cnt += map[S[j]];
        return cnt;
    }
};
```