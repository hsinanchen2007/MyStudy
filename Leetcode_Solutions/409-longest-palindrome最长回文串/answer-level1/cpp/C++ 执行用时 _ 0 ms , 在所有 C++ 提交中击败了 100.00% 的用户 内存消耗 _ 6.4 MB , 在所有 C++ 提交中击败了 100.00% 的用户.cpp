### 解题思路
定义变量num表示最长回文串的长度。
统计字符串s内每种字符的数量。
遍历每种字符的数量，若数量为偶数则直接添加到num内，若数量为奇数则-1再添加到num内，最后输出num时输出num+1。
### 代码

```cpp
class Solution {
public:
    int longestPalindrome(string s) {
        
        int a[58]={0};
        
        int i;
        
        for(i=0;i<s.size();i++)
        {
            a[s[i]-'A']++;
        }
        
        int num=0;
        int j=0;
        
        for(i=0;i<58;i++)
        {
            if(a[i]%2==0)//偶
            {
                num+=a[i];
            }
            else if(a[i]%2==1)//奇
            {
                num+=a[i]-1;
                j=1;
            }
        }
        
        if(j==1)
        {
            num++;
        }
        
        return num;

    }
};
```