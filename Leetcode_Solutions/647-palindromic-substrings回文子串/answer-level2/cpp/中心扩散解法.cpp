
**中心扩散解法**: 
遍历每一个索引，以这个索引为中心，利用“回文串”中心对称的特点，往两边扩散，看最多能扩散多远。
备注：回文串的长度可能是奇数，也可能是偶数。

```
class Solution {
public:
    
    int expandAroundCenter(string s, int left, int right) {
        int L = left, R = right;
        int ct = 0;
        while(L>=0 && R<s.length() && s[L] == s[R]) {
            ct++;
            L--;
            R++;
        }
        return ct;
    }
    
    int countSubstrings(string s) {
        if(s.length() < 1) return 0;
        
        int res = 0;
        
        for(int i=0; i<s.length(); i++) {
            int ct1 = expandAroundCenter(s, i, i);//一个元素为中心
            int ct2 = expandAroundCenter(s, i, i + 1);//两个元素为中心
            res += ct1;
            res += ct2;
        }
        return res;
    }
};
```

参考：[最长回文子串]( https://leetcode-cn.com/problems/longest-palindromic-substring/)