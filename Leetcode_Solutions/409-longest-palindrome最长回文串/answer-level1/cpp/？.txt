### 解题思路
（我就看看为什么能双百，思路简单得很

### 代码

```cpp
class Solution {
public:
    int longestPalindrome(string s) {
        int len=0;
        int flag=0;
        int numofab[128]={0};
        for(int i=0;i<s.length();i++)
        {
            numofab[s[i]]++;
        }
        for(int k=0;k<128;k++)
        {
                if(numofab[k]%2!=0)
                {
                    flag++;
                    numofab[k]--;
                }
        len+=numofab[k];
        }
        if(flag)
            len++;
        return len;
    }
};
```