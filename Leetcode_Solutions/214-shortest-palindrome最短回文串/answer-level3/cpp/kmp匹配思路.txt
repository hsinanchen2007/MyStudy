### 解题思路
此处撰写解题思路
1.
s1=aabb对应的是bbaabb
首先把s1=aabb反转为s2=bbaa
将s2视为匹配串计算next索引值
2.
将得到的索引值使用匹配当主串的指针移到最后一位并且模式串的指针指在了某一位，让他们相减得到是需要附加的字串
注：
            int len1=s.length();
            int len2=t.length();
            while(i<len1&&j<len2)
            与 while(i<s.length()&&j<t.length())结果不相同
            不知道为什么，有知道的大佬告诉小弟一声，感激。

### 代码

```cpp
class Solution {
public:
    void nextidx(const string &T, int nextarr[])
    {
        int i=0;
        int j=-1;
        nextarr[0]=-1;
        while(i<T.length()-1)
        {
            if(j==-1||T[i]==T[j])
            {
                i++;
                j++;
                if(T[i]==T[j])
                {
                    nextarr[i]=nextarr[j];
                }
                else
                {
                    nextarr[i]=j;
                }
            }
            else
            {
                j=nextarr[j];
            }
        }
    }
    string shortestPalindrome(string s) {

            if(s.length()<=0)
                return s;
            string t=s;
            int next[t.length()];
            nextidx(s,next);
            reverse(t.begin(),t.end());
            int i=0;
            int j=0;
            int len1=s.length();
            int len2=t.length();
            while(i<len1&&j<len2)
           {
               if(j==-1||s[j]==t[i])
               {
                   i++;
                   j++;
               }
               else
               {
                   j=next[j];
               }
           }
           int idx=i-j;
           return t.substr(0,idx)+s;
    }
};














```