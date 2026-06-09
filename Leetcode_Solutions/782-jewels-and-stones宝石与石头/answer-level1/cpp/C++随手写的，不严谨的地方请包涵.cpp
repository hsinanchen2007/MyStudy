只实现算法，合法性判断之类的检测就没写
```
class Solution {
public:
    int numJewelsInStones(string J, string S) {
        map<char, int> m;
        int c = 0;
        
        for_each(S.begin(), S.end(), [&](const char& v) { m[v]++; });    
        for_each(J.begin(), J.end(), [&](const char& v) { c += m[v]; });
        return c;
    }
};
```