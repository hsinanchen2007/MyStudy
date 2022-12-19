### 解题思路
递归操作，若下一字符对应数值比当前字符数值大，则用下一字符的数值减去当前数值

### 代码

```cpp
class Solution {
public:
    unordered_map<char,int>mp;
    Solution(){
        mp={{'I',1},{'V',5},{'X',10},{'L',50},{'C',100},{'D',500},{'M',1000}};
    }
    int romanToInt(string s) {
        return romanToInt(s,0);
    }
    int romanToInt(string s,int i){
        if(i==s.size())return 0;
        int res=mp[s[i++]];
        if(i<s.size()&&mp[s[i]]>res){
            res=mp[s[i]]-res;
            i++;
        }
        return res+romanToInt(s,i);
    }
};
```