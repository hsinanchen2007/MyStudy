### 解题思路
因为两个字符串的长度是一样的，就依次遍历字符串，如果这两个字符都没有在哈希表中出现过，就把字符和位置加入哈希表中。如果在哈希表中都存在的话就判断值是否相等。
其实说这么啰嗦，也就是哈希表中存的就是每个字符第一次出现的位置

### 代码

```cpp
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char,int> sHash;
        unordered_map<char,int> tHash;
        for(int i =0;i<s.size();i++){
            if(sHash.count(s[i])&&tHash.count(t[i])){
                if(sHash[s[i]]!=tHash[t[i]])
                    return false;
            }
            else if(sHash.count(s[i]) || tHash.count(t[i]))
                return false;
            else{
                sHash[s[i]]=i;
                tHash[t[i]]=i;
            }
        }
        return true;
    }
};
```