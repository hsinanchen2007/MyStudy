### 解题思路
首先了解到回文串是对称的，比如“aaaa”，“aacaa”这种情况，长度为奇数时存在一个中心点。
遍历字符串s，统计字符出现次数：如果次数是偶数则加入回文串两边；如果是奇数，则考虑可能存在中心点的情况，判断当前回文串长度是偶是奇，是偶则可将它视为中心点，加入；是奇则排除。
最后每用完一个字符后，将次数置0，避免重复计算。

### 代码

```c
int longestPalindrome(char * s){
    int count[128] = {0};
    int res = 0;
    int len = strlen(s);
    for(int i=0;i<len;i++)
        count[s[i]]++;
    for(int i=0;i<len;i++)
    {
        res += count[s[i]]/2 *2;  //字母是偶数个时，则全部加入；奇数时，则加入偶数个
        if(count[s[i]]%2==1 && res%2==0)//中心点唯一的情况，即加入该字符，长度为奇数
            res++;
        count[s[i]] = 0;
    }
    return res;
}
```