### 解题思路
先用map统计每个字符出现的次数，然后遍历一遍map，更新答案（次数-次数%2），出现偶数次数的字符一定可以回文（左边一半右边一般即可），若有出现奇数次的字符则标记一下，最后把答案+1就行了（因为可以放中间）

### 代码

```cpp []
class Solution {
public:
    int longestPalindrome(string s) {
        bool f=false;
        map<char,int> ma;
        map<char,int>::iterator it;
        for(int i=0;i<s.size();++i){
            ma[s[i]]++;
        }
        int ans=0;
        for(it=ma.begin();it!=ma.end();it++){
            if((it->second)%2) f=1;
            ans+=(it->second)-(it->second)%2;
        }
        return f==0?ans:ans+1;
    }
};
```
```python []
class Solution(object):
    def longestPalindrome(self, s):
        """
        :type s: str
        :rtype: int
        """
        dic={}
        for ch in s:
            if dic.get(ch,0)==0:
                dic[ch]=1
            else:
                dic[ch]+=1
        f=0
        ans=0
        for cnt in dic.values():
            if cnt%2:
                f=1
            ans+=cnt-cnt%2
        if f==0:
            return ans
        else:
            return ans+1
```