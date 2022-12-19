### 解题思路
由后往前找。退出条件需要注意，当前不是字符，但曾经记录过字符个数。若仅仅不是字符，有可能是字符串后面的脏数据。

### 代码

```c


int lengthOfLastWord(char * s){
    int l;
    int i;
    int res = 0;

    if(NULL == s)
        return 0;

    l = strlen(s);
    for(i = l-1; i >=0; i--)
    {
        if(isalpha(s[i]))
            res++;
        else
            if(res)
                break;
    }

    return res;
}


```