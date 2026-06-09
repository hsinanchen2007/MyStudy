### 解题思路
执行用时 :
4 ms
, 在所有 C 提交中击败了
88.65%
的用户
内存消耗 :
7.6 MB
, 在所有 C 提交中击败了
41.61%
的用户
前后两个指针 若碰到不是字符或者是数字直接跳过 若碰到相同则同时向中间移动
### 代码

```c
bool isPalindrome(char * s){
    if(strlen(s) == 0 ||strlen(s) == 1)  return true;    //空字符串 定义为有效回文串
    int len = strlen(s);
    int m = 0;
    int n = len-1;
    while(n>m)
    {
        if(!isalnum(s[m]))  
        {
            m++;
            continue;
        }
        if(!isalnum(s[n]))
        {
            n--;
            continue;
        }
        if(tolower(s[m]) == tolower(s[n]))
        {
            m++;
            n--;
            continue;
        }
        if(tolower(s[m]) != tolower(s[n]))
        {
            return false;
        }
    }
    return true;
}
//isalnum   判断一个字符是否是数字或字母
//isalpha   判断一个字符是否是字母
//tolower   大写转小写
    //将字符串中的特殊字符减去
 /*   for(int i=0;i<len;i++)
    {
        if(!isalnum(s[i]))
        {
            if(i == len-1)
            {
                len--;
                break;
            }
            for(int j=i+1;j<len;j++)
            {
                s[j-1] = s[j];
            }
            len--;
            i--;
        }
    }
    */
```