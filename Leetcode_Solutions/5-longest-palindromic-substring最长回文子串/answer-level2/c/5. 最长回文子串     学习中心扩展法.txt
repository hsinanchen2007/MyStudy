### 解题思路
给定一个字符串 s，找到 s 中最长的回文子串。你可以假设 s 的最大长度为 1000。

示例 1：

输入: "babad"
输出: "bab"
注意: "aba" 也是一个有效答案。


主要是封装一个中心扩展函数， 返回回文长度。
主函数则一次遍历调用此 中心扩展函数   取最大值即可。

### 代码

```c
int expand(int left, int right, char *s, int max_len){
    int len=0;
    /*左游标>=0， 右游标<最大长度*/
    while(left >= 0 && right < max_len && s[left] == s[right]){
        left--;
        right++;
    }
    return right - left - 1;
}


char * longestPalindrome(char * s){
    int max_len =strlen(s);
    int len_odd, len_even, i=0, len=0, len_temp,start=0;
    if (max_len == 0)
        return s;

    for (i=0; i<max_len; i++){
        /*巧妙将i同时给左和右  来处理基数回文*/
        len_odd = expand(i, i, s, max_len);
        len_even = expand(i, i+1, s, max_len);
        len_temp = len_odd > len_even ? len_odd : len_even;
        if(len < len_temp){
            len = len_temp;
            start  = i - (len - 1)/2;
        }
    }
    if(len >= 2){
        s[start + len] = '\0';
        return s+start;
    }else{
        s[1] = '\0';
        return s;
    }
}
```