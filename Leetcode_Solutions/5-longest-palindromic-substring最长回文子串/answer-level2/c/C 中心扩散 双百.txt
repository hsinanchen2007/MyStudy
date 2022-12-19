![image.png](https://pic.leetcode-cn.com/ced3ebaca6b05eb57f5bc3b9da89d3ed32666073ea8ae51d0b1ec33f63734363-image.png)

### 解题思路
此处撰写解题思路
使用中心扩散法寻找回文数组，但是回文数组有两种可能，奇数个和偶数个。
设置两个指针left和right，分别位于对称中心的两边，向两边扩散，中心对称点是重复字符串则当成一个字符处理。
### 代码

```c
char * longestPalindrome(char * s){
    if(strlen(s)==0||strlen(s)==1) return s;
    int i,start,left,right,count,len;
    start = len =0;
    for(i=0;s[i]!='\0';i+=count){
        count = 1;
        left=i-1;
        right = i+1;
        while(s[right]!='\0'&&s[i]==s[right]){ //处理重复字符串
            right++;
            count++;
        }
        while(left>=0 && s[right]!='\0' && s[left] == s[right]){
            left--;
            right++;
        }
        if(right-left-1>len){
            start = left+1;
            len = right-left-1;
        }
    }
    s[start + len] = '\0';      // 原地修改返回
    return s + start;
}
```