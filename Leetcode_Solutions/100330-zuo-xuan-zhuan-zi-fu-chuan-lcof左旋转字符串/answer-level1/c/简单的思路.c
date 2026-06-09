### 解题思路
先用一组数组保存要左旋的部分，然后用两个指针将不需要左旋的部分搬移到前面。

### 代码

```c
char* reverseLeftWords(char* s, int n)
{
    char cache[10001];  //缓存部分
    int i;

    char *p_s=s; //辅助指针
    char *D=s;   //记住首地址

    for(i=0;i<n;i++) //保存左旋部分
    {
        cache[i]=*s;
        s++;
    }

    while(*s!='\0')       //搬移部分
    {
        *p_s=*s;
        p_s++;
        s++;
    }

    for(i=0;i<n;i++)          //左旋
    {
        *p_s=cache[i];
        p_s++;
    }

    s=D;
    
    return s;
}
```