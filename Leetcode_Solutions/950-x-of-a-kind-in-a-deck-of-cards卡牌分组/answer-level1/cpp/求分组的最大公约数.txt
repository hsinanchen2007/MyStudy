### 解题思路
1、按相同数字分组，统计各个分组的大小
2、求所有分组大小的最大公约数(欧几里德：辗转相除)， 若最大公约数大于2，说明各个分组都能被均分。

### 代码

```cpp
class Solution {
public:
int gcd(int a, int b){
    if(b == 0)
        return a;
    return gcd(b, a % b);
}


bool hasGroupsSizeX(vector<int>& deck) {
    unordered_map<int ,int> imap;
    for(int v: deck)
        imap[v]++;
    
    int v = imap[deck[0]];
    for(pair<int, int> p: imap){
        if(v > p.second)
            v = gcd(v, p.second);
        else
            v = gcd(p.second, v);
        
        if(v == 1)
            return false;
    }
    
    return true;
}

};
```