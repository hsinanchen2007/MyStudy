根据题意：
    组成的回文字符串ss如果是偶数的话，字符串ss必定是由出现次数为偶数的字符组成。
    组成的回文字符串ss如果是奇数的话，字符串ss必定是由出现次数为偶数的字符，加上出现次数奇数的字符组成。
我们可以想到以下思路：
    1.设置map统计输入字符串s的个数，然后假设返回回文字符串长度结果为int res=0.
    2.遍历输入的字符串s
        1）如果之前没有在map中出现过，那么插入。
        2）如果之前该字符已经在map中出现过，那么将res+2，再删除掉。
    3.最后将res和输入字符串s.size()进行对比
        如果res<s.size(),那么说明必定存在出现次数为奇数个的字符，故return res+1即可
        如果两者相等，说明输入字符串恰好可以组成回文字符串。
```
class Solution {
public:
    int longestPalindrome(string s) {
        map<char,int> m;
        int res=0;
        for(char c:s)
        {
            m[c]++;
            if(m[c]==2)
            {
                res+=2;
                m[c]=0;
            }
        }
        if(res<s.size())return res+1;
        else return res;
    }
};
```
![image.png](https://pic.leetcode-cn.com/062165aa7c001d4bfa6c5ed8c2b753c2faa114385328754d9abc2072ea0461fe-image.png)
