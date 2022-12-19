### 解题思路
为字符串s,t设置两个辅助数组a、b，用来统计字母出现次数。

### 代码

```cpp
class Solution {
public:
    bool isAnagram(string s, string t) {
        int a[26]={0},b[26]={0};
        int lengths=s.length();
        int lengtht=t.length();
        for(int i=0;i<lengths;++i){
            a[s[i]-'a']++;
        }
        for(int i=0;i<lengtht;++i){
            b[t[i]-'a']++;
        }
        //比较
        for(int i=0;i<26;++i){
            if(a[i]!=b[i])
                return false;
        }
        return true;
    }
};
```