### 解题思路
其实就是遇到不同的先跳过，但是这里要注意的是最后的成功判断条件，以及中间那个值的处理方式。
![000.png](https://pic.leetcode-cn.com/e04e8310eaa3bb878bc9f47b55daf52d4b1018576e4e03242d4d112552e34f30-000.png)

### 代码

```c
bool validPalindrome(char* s)
{
    int m = strlen(s);
    int i = 0; int j = m - 1;
    int a = 0; int b = m - 1;
    int count = 0;
    int count1 = 0;
    int x = m;
    while (j >= x / 2)
    {
        if (s[i] == s[j])
        {
            i++;
            j--;
        }
        else
        {
            i++;
            count++;
            x++;
        }
        if (count > 1)
            goto kk;
    }kk:
    while (a <= m / 2)
    {
        if (s[a] == s[b])
        {
            a++;
            b--;
        }
        else
        {
            b--;
            count1++;
            m--;
        }
        if (count1 > 1)
            goto jj;
    }jj:

    if( (count<2||count1 < 2 )&& (j == x/ 2-1 || a == m/ 2+1))
    return true;
    else
        return false;
}
```