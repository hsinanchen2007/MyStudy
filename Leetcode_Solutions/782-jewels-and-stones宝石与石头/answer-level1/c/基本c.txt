### 解题思路
此处撰写解题思路 注意第一层y循环做完之后，要把第二层的参数归零。

### 代码

```c
int numJewelsInStones(char * J, char * S)
{
    int i=0,t=0,flag=0;
    while(J[i]!='\0')
    {
        t=0;
        while(S[t]!='\0')
        {
            if(J[i]==S[t])
            {
                flag++;
            }
            t++;
        }
        i++;
    }
    return flag;
}
```