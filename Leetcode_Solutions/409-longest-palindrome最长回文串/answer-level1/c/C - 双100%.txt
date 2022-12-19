### 解题思路
此处撰写解题思路

### 代码

```c
int transCharToInt(char* ch)
{
    int retv;
    // ascii : 'A' , 65
    if ((int) ch >= 65 && (int) ch <= (65+25))
        retv = (int)ch - 65;
    else if ((int) ch >= 97 && (int)ch <= (97 + 25))
        retv = (int)ch - 71;
    
    return retv;
}   
int longestPalindrome(char * s){

    int l = strlen(s);

    int hitNum[53] = {0};

    for (int i = 0 ; i < l ;i++)
        hitNum[transCharToInt(*(s+i))]++;

    int ans = 0;
    int flag = 0;
    for (int i = 0;i < 52;i++)
    {
        //if (hitNum[i] != 0 && hitNum[i] % 2 == 0)
        ans += hitNum[i];
        if (hitNum[i] % 2 == 1)
        {
            //ans += hitNum[i] / 2;
            ans--;
            flag = 1;
        }
    }
    if (flag) 
        ans++;
    
    return ans;
}
```