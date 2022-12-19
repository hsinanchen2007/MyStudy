### 解题思路
使用unordered_map存储字符串元素的序号，改写原字符串，判断二者是否相等

### 代码

```cpp
class Solution {
public:
    string deal(string s,unordered_map<char,int>& x,int p){
        for(int i=0;i<s.size();i++)
            if(x[s[i]]==0){
                x[s[i]]=p++;
                s[i]='a'+x[s[i]]-1;
            }
            else
                s[i]='a'+x[s[i]]-1;
        return s;
    }
    bool isIsomorphic(string s, string t) {
        unordered_map<char,int> x,y;
        if(deal(s,x,1)==deal(t,y,1))
            return true;
        else
            return false;
    }
};
```