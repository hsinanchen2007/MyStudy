### 解题思路
此处撰写解题思路

### 代码

```c
int numJewelsInStones(char * J, char * S)
{
    int hash[58] = {0};                                           //a - A + 1 = 58
    int i = 0;
    while(J[i]!='\0')
    {
        hash[J[i]-65] = 1;                                        //若是宝石，则将此位置1
        i++;
    }
    i = 0;
    int result = 0;
    while(S[i]!='\0')
    {
        if(hash[S[i]-65]!=0)                                       //hash数组不为0则表示此位是宝石
        {
            result++;
        }
        i++;
    }
    return result;
}
```