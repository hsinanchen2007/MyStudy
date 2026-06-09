### 解题思路
代码很长。

### 代码

```c
bool checkRecord(char * s){
    int A=0;
    int L=0;
    for(int i=0;i<strlen(s);i++)
    {
        if(s[i]=='A')
        {
            A++;
        }
        else if(s[i]=='L')
        {
            int temp=1;
            for(int j=i+1;j<strlen(s);j++)
            {
                if(s[j]=='L')
                {
                    temp++;
                }
                else
                {
                    break;
                }
            }
            if(temp>L)
            {
                L=temp;
            }
        }
    }
    if(L>2||A>1)
    {
        return false;
    }
    else
    {
        return true;
    }
}
```