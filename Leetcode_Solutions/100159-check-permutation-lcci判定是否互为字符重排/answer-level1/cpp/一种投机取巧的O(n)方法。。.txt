### 解题思路
由于字符串给的都是字母，则可知：
**若能被重排，每个字母在字符串中出现的次数必是一样的。**
数组记录每个字母出现的次数，挨个比对完成。

### 代码

```cpp
class Solution {
public:
    bool CheckPermutation(string s1, string s2) {
        if(s1.size()!=s2.size()) return false;
        int ss1[30]={0};
        int ss2[30]={0};
        for(int i=0;i<s1.size();++i)
        {
            ++ss1[s1[i]-'a'];
            ++ss2[s2[i]-'a'];
        }
        for(int i=0;i<27;++i)
        {
            if(ss1[i]!=ss2[i]) return false;
        }
        return true;
    }
};
```