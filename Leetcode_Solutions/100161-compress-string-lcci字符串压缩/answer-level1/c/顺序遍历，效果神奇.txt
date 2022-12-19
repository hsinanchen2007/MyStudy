### 解题思路
此处撰写解题思路
![image.png](https://pic.leetcode-cn.com/e81a090259a91dca9c34bacf91d8d7bae32e7dca33d8fc14bc18060881cb1e40-image.png)

### 代码

```c
char* compressString(char* S){
    char s[333333] =  {0};
    s[0] = S[0];
    char c = S[0];
    int i,j=1 ,n = strlen(S);
    if(n <= 2)
        return S;
    int count = 1;
    for(i = 1; i < n; i++)
    {
        if(S[i] == c)
            count ++;
        else
        {
            j = jia(s, j , count);
            s[j++] = S[i];
            count = 1;
            c = S[i]; 
        }
    }
     j = jia(s, j , count);
    return (strlen(s) < n? s:S);
}
int jia(char * s, int j ,int num)
{
    if(num < 10)
    {
        //*(s + j) = num+'0';
        //j++;
        s[j++] = num+'0';
        return j;
    }
    j = jia( s , j ,num/10);
    //*(s + j) = num%10+'0';
    //j++;
    s[j++] = num%10+'0';
    return j;
}

```