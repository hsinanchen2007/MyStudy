### 解题思路
此处撰写解题思路

### 代码

```c
//子函数：反转p_left和p_right之间的字符
void reverse(char* s, int p_left, int p_right) 
{    
    while(p_left < p_right)
    {
        char tmp;
        tmp = s[p_left];
        s[p_left] = s[p_right];
        s[p_right] = tmp;
        
        p_left++;
        p_right--;
    }
}                   标准需要掌握的
//求解函数：区间控制+子函数调用
char* reverseStr(char* s, int k)
{
    int s_len = strlen(s);
    for(int i = 0; i < s_len; i += 2 * k)  //跟据题意，两种不同的情况
    {
        if(i + k <= s_len)
            reverse(s, i, i+k-1);
        else
            reverse(s, i, s_len-1);
    }
    return s;
}
```