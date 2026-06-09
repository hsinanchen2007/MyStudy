这道题就是在反转字符串1（整体字符串全部反转）的基础上，设置了反转区间进行分段反转。因此，可以直接将整体字符串反转的函数当做本函数的调用子函数，本函数的主体进行字符串的分段控制即可。
```
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
}
//求解函数：区间控制+子函数调用
char* reverseStr(char* s, int k)
{
    int s_len = strlen(s);
    for(int i = 0; i < s_len; i += 2 * k)
    {
        if(i + 2 * k <= s_len || i + k <= s_len)
            reverse(s, i, i+k-1);
        else
            reverse(s, i, s_len-1);
    }
    return s;
}
```
