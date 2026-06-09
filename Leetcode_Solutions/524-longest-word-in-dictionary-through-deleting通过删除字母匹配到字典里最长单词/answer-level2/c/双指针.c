### 解题思路
数据结构书上有讲过查询子串  方法   就是双指针 
但是这个解法有一个漏洞就是  最符合字典序的那里 不够全面，只判断了 第一个字母倘若第一个相同则第二个就无法判断

### 代码

```c
char * findLongestWord(char * s, char ** d, int dSize)
{
    char *result = "";      //g如果为空则输出此
    int len = -1;
    for(int i = 0; i<dSize ; i++)
    {   
        char *p = s;  char *q = d[i];
        int x= 0,y= 0;
        while(p[x] !='\0' && q[y] != '\0')    //判断是否是子串
        {
            if(p[x] == q[y])
            {
                x++;
                y++;
            }
            else
                x++;
        }
        if(q[y] == '\0')        //是子串就计入 result   
        {
            if(y>len)           //判断最符合结果的
            {
                len = y;
                result = q;
            }
            else if(len == y && q[0] - result[0] <0)
            {
               result = q;
            }
        }
    }
    return result;
}
```