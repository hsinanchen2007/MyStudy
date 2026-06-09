### 解题思路
本题解目前写了两种解法
1. 动态规划法  
    1.核心是创建一个记录子串是否是回文串的数组。判断条件：若子串回文 子串左右各缩进一个字符的子串也必须是回文。从短到长不断记录，就能找到最长的回文子串 
2. 中轴线法
    1.因为中轴线是可以取在两个数中间的空白处，所以中轴线的取法有2n-1种。 遍历各种中轴线取法，在做每种取法时，从中轴线开始，左右数组指针分别左右移动，判断两侧是否相同。直到不相同就记录下当前长度。找出长度最长的回文


### 代码

```csharp
public class Solution {
    public string LongestPalindrome(string s) {
        //动态规划  创建一个数组记录各个字串的回文情况 长字串要是回文 则P[start+1，end-1]就必须是回文
        
        int n = s.Length;
        bool[,] P = new bool[n,n];
        string res = "";
        for(int len = 1 ; len <= n;len++)
        {
                for(int start = 0;start < n;start++)        
            {
                int end = start + len - 1;
                if(end >= n)
                {
                    break;
                }
                P[start,end] = (len == 1||len == 2||P[start+1,end-1])&&s[start] == s[end];//回文的判断条件
                if(P[start,end] && len > res.Length)  //创建记录数组的过程中就可以寻找最长回文子串
                {
                    res = s.Substring(start,len);
                }  
            }
        }
    return res;
    
    //中轴线算法 
        int n = s.Length;
        string res = "";
        int end = 2 * n - 1;  //有2n-1种中轴线取法
        for(int i = 0;i < end; i++)
        {
            double mid = i/2.0;
            int p = (int)(Math.Floor(mid));  //如果中轴在中间就取下
            int q = (int)(Math.Ceiling(mid));//取上
            while(p >= 0 && q < n)  
            {
                if(s[p] != s[q])  //判断 左右数组指针指向的元素 是否相等
                break;
                else
                {
                    p--;
                    q++;
                }                
            }
            int len = q-p-1;
            if(len>res.Length)
                res = s.Substring(p+1,len);
        }
        return res;
    }
}
```