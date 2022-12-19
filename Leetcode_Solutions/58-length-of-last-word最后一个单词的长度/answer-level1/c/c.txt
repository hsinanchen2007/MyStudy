### 解题思路
此处撰写解题思路
1、出现‘ ’时，保留上一段字符串的长度，并且计数器置为0；

### 代码

```c
int lengthOfLastWord(char * s){
    int length = 0, tmp = 0;
    int i = 0;

    while(s[i] != '\0')
    {
        if(s[i] != ' ')
        {
            tmp++;
        }
        else
        {
            if(tmp)
            {
                length = tmp;
            }

            tmp = 0;
        }
        
        i++;
    }

    if(tmp)
    {
        length = tmp;
    }

    return length;
}
```