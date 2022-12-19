## 两个哈希表相互映射
**1. 哈希表as[]的下标代表s的字符，内容代表对应t的字符
2. 哈希表at[]的下标代表t的字符，内容代表对应s的字符**
```cpp
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int len = s.size();
        int as[128]={0}, at[128]={0}; //哈希表
        for(int i=0; i<len; i++){
            if(as[(int)s[i]]==0){
                as[(int)s[i]] = t[i];
            }
            else if(as[(int)s[i]]!=t[i]){
                return false;
            }
            if(at[(int)t[i]]==0){
                at[(int)t[i]] = s[i];
            }
            else if(at[(int)t[i]]!=s[i]){
                return false;
            }
        }
        return true;
    }
};
```
## 比较字符第一次出现的索引值
可能会费时，但不需要额外空间
```cpp
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int len=s.size();
        for(int i=0; i<len; i++){
            if(s.find(s[i]) != t.find(t[i])) return false;
        }
        return true;
    }
};
```
