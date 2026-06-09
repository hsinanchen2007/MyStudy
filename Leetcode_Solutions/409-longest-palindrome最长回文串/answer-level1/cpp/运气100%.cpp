### 解题思路
1.先用a数组通过ascii转下标保存每个字母出现的次数
2.字母出现为奇数个的话，肯定要舍弃一个变成偶数个，统计出现为奇数的字母个数
3.原字符串总长减去出现为奇数的字母个数，然后因为回文串中间可以单独存在一个字母，因此再+1，也就是slen-（len-1），就是最长长度
![)5PGB\]Y341QVJVRYENJTE@1.png](https://pic.leetcode-cn.com/f9788c6bc0d0e57615027204497b3aa93ed2c26b130c95e7f837b3cdee7f74ef-\)5PGB%5DY341QVJVRYENJTE@1.png)



### 代码

```cpp
class Solution {
public:
    int longestPalindrome(string s) {
        int slen=s.length(),a[52]={0},len=0;
        for(int i=0;i<slen;i++)
            if((int)s[i]>=97)
                a[(int)s[i]-97]++;
            else
                a[(int)s[i]-65+26]++;
        for(int i=0;i<52;i++)
            if(a[i]%2==1)
                len++;
        return slen-(len==0?len:len-1);
    }
};
```