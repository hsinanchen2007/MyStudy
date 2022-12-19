### 解题思路
1.使用unorder_map做字母对应映射。
2.当map中没有则加入字母映射对，若是发现映射对不对则返回false，若是所有的映射都正确则返回true。

### 代码

```cpp
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char,char> s_map;
        unordered_map<char,char> t_map;
        for(int i = 0; s[i] != '\0'; i++){
            char ss = s[i];
            char tt = t[i];
            if(s_map.count(ss)){
                if(s_map[ss] != tt)    return false;
            }
            else if(t_map.count(tt)){
                if(t_map[tt] != ss)  return false;
            }
            else{
                s_map[ss] = tt;
                t_map[tt] = ss;
            }
        }
        return true;
    }
};
```