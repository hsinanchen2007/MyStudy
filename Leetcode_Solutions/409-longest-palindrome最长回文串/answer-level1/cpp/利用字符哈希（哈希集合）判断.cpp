### 解题思路
**方法一：利用哈希集合：字符哈希**
1.设置一个字符哈希表char_map[128]，用数组代替。用来统计字符串中字符的个数。
    其中128代表有128个字符ASCII码：
    第0～32号及第127号(共34个)是控制字符或通讯专用字符，如控制符：LF（换行）、CR（回车）、FF（换页）、DEL（删除）、BEL（振铃）等；通讯专用字符：SOH（文头）、EOT（文尾）、ACK（确认）等；
    第33～126号(共94个)是字符，其中第48～57号为0～9十个阿拉伯数字；65～90号为26个大写英文字母，97～122号为26个小写英文字母，其余为一些标点符号、运算符号等。

2.设置最长回文个数max_length。用来记录回文长度。

3.设置中心点flag=0。用来记录回文中心字符长度。

4.遍历每一个字符。
    当字符个数为偶数时，最长回文加字符个数；（因为每个字符都可以看做是回文字符）
    当字符个数为奇数时，最长回文加字符个数减1，并设置中心字符flag=1。（有一个字符肯定不是回文字符且中心字符只可能有一个）

5.返回max_length+flag；


**时间复杂度**：O[N] 遍历每个字符
**空间复杂度**：O[1] 
### 代码

```cpp
class Solution {
public:
    int longestPalindrome(string s) {
        int char_map[128]={0};
        int max_length = 0;
        int flag =0;
        for(int i=0; i<s.length();i++)
        {
            char_map[s[i]]++;
        }
        for(int i=0;i<128;i++)
        {
            if(char_map[i]%2==0)
            {
                max_length+=char_map[i];
            }
            else
            {
                flag =1;
                max_length+=char_map[i]-1;
            }
        }
        return max_length+flag;
    }
};
```