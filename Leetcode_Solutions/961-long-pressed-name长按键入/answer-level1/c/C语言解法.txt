保留上一次遍历的字符(last_ch)，等到type不等于name的时候判断type是不是等于last_ch

执行用时 : 4 ms, 在Long Pressed Name的C提交中击败了98.80% 的用户

内存消耗 : 6.7 MB, 在Long Pressed Name的C提交中击败了93.33% 的用户


```c
bool isLongPressedName(char * name, char * typed){
    char last_ch;
    while(*name)
    {
        if(*name == '\0')
        {
            while(*typed != '\0')
            {
                if(*typed != last_ch)
                    return false;
            }
        }

        if(*typed != *name)
        {
            if(*typed != last_ch)
                return false;
            typed++;
        }
        else
        {
            last_ch = *name;
            name++;
            typed++;
        }
    }
    
    return true;
}
```