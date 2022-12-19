统计字符串中出现奇数次的字母的次数，如abbacab中，a出现3次，然后令odd统计这种字母的个数，上述串中a，b均出现3次，所以odd=2；如果odd>k,这种情况无法构造回文（可以自己试试），然后odd<k，可以先构造odd个回文串，每个串分别为对应的字母，剩下的就是出现偶数次的字母了，偶数次字母就很好构造了。

### 代码

```cpp
class Solution {
public:
    bool canConstruct(string s, int k) {
    if(s.size()==k) return true;
    if(s.size()<k)return false; 
    int hashtable[26]={0};int len=s.size();
    for(int i=0;i<len;i++){
        hashtable[s[i]-'a']++;
    }
    int odd=0;
    for(int i=0;i<26;i++){
        if(hashtable[i]==0) continue;
        if(hashtable[i]%2==1)odd++;
    }
    if(odd>k) return false;
    else return true;
    }
};
```