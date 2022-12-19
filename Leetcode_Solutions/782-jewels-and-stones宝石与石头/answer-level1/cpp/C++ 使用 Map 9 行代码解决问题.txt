
核心就是S中所有的字符都统计一遍，然后计算J中所有对应的字符的个数信息。
```cpp
class Solution {
public:
    int numJewelsInStones(string J, string S) {
        map<char,int> maps;
        for(auto &item : S){
            maps[item]++; 
        }
        int res = 0;
        for(auto &item : J){
            res += maps[item];
        }
        return res;
    }
};
```
