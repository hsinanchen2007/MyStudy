### 解题思路
为啥跟人家思路都一样，就是写不对，呜呜呜┭┮﹏┭┮
 //好好想想递归是怎么运行的
//递归入口，结束，推动条件
### 代码

```c
/* 尾递归 */
char *countHelper(char *s, int n)
{
    if (n == 1)
        return s;
    else
    {
        //求下一个数
        int count;
        char ch[10000];
        char *p = ch;
        //一直读数
        while (*s!='\0')
        {
            count = 1;
            //如果一直是同一个数
            while (*s==*(s+1))
            {
                count++;
                s++;
            }
            //下一个数更新
            *p++ = (char)(count+'0');
            *p++ = *s++;
        }
        return countHelper(ch, n - 1);
    }
}

char *countAndSay(int n)
{
    return countHelper("1", n);
}

```