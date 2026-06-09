### 解题思路
找到字符串中最大的数，然后以这个数为中心，将字符串分为左右两部分计算，左边的减去右边的加上。
使用分治策略对左右两个子串使用同样的方法计算。
### 代码

```cpp
class Solution {
public:
    map<char, int> f = {{'I',1},{'V',5},{'X',10},{'L',50},{'C',100},{'D',500},{'M',1000}};
    int split(string s){
        int max = 0;
        int max_i = -1;
        for(int i = 0; i < s.size(); i++){
            if(f[s[i]] > max){
                max = f[s[i]];
                max_i = i;
            }
        }
        return max_i;
    }
    int romanToInt(string s) {
        if(s.size() == 0){
            return 0;
        }
        int pos = split(s);
        int res = f[s[pos]];
        return res - romanToInt(s.substr(0, pos)) + romanToInt(s.substr(pos + 1, s.size() - pos - 1));
    }
};
```