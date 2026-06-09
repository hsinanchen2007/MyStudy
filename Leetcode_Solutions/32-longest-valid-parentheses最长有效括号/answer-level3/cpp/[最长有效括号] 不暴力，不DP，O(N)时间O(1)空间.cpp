对于括号问题我们知道，当右括号的数目大于左括号时，必定会失配，那么我们可以记录下左括号和右括号的数目，每当右括号数目大于左括号时，就将它们清零，当右括号数目等于左括号时，把他们的和储存在结果中。
不过如果仅仅只是这些，还是考虑的不够全面，看看下面的例子：
**()((())**
这个结果应该是4，但是按照刚才的算法，算出的结果是2。
这是因为当字符串到达结尾了，右括号还没能完全匹配上左括号，右括号不等于左括号因此漏算了这个子串的长度，此时只需要倒序遍历一遍，计算出倒序遍历的最长子串，再取二者中最大值。
原因是如果出现到结尾右括号没能匹配上左括号时，在结尾必定是左括号多于右括号，此时反向遍历能够得到这个末尾子串的长度。

下面附上代码和运行时间：
![QQ图片20200307162454.png](https://pic.leetcode-cn.com/895d6cca93a5923ee5ad78bb46c58d89c6f28045f4c0363f6cf1713cce3689a7-QQ%E5%9B%BE%E7%89%8720200307162454.png)
```
class Solution {
public:
int longestValidParentheses(string s) {
    int end=0,lnum=0,rnum=0,lmax=0,rmax=0;
    while(end<s.size())
    {
        if(s[end]=='(')
            lnum++;
        else 
            rnum++;
        if(lnum==rnum)
            {if(lnum+rnum>lmax)
                lmax=lnum+rnum;}
        else if(lnum<rnum)
        {   
            lnum=0;rnum=0;
        }
        end++;
    }
    end=s.size()-1,lnum=0,rnum=0,rmax=0;
    while(end>=0)
    {
        if(s[end]=='(')
            lnum++;
        else 
            rnum++;
        if(lnum==rnum)
            {if(lnum+rnum>rmax)
                rmax=lnum+rnum;}
        else if(lnum>rnum)
        {   
            lnum=0;rnum=0;
        }
        end--;
    }
    return max(rmax,lmax);

    }
};
```

