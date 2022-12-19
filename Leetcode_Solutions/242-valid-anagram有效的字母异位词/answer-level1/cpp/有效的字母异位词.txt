

```cpp
class Solution {
public:
    //构建哈希数组，用索引0~26代表a~z
    bool isAnagram(string s, string t) {
        if(s.length()!=t.length())return false;
        //普通数组必须提前分配空间，或者用动态数组
        int hashArr[26]={0};
        for(int i=0;i<s.length();++i){
            hashArr[s[i]-'a']++;     
        }     
        for(int i=0;i<t.length();++i){
            hashArr[t[i]-'a']--;
        }
        //判断个数也可用i<26
        for(int i=0;i<sizeof(hashArr)/sizeof(hashArr[0]);++i){

            if(hashArr[i]!=0)return false;
        }
        return true;
    }
};
```