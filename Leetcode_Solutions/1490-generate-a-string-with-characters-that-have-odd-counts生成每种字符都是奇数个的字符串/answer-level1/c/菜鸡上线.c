### 解题思路
![QQ图片20200325183711.png](https://pic.leetcode-cn.com/8d0183ca94b858a22d73819b86f16463832ee9cb2366d4df08f92d978d772089-QQ%E5%9B%BE%E7%89%8720200325183711.png)

### 代码

```c
char * generateTheString(int n)
{
    char* data = (char*)malloc(sizeof(char) * (n + 1));
    data[n] = '\0';
    if ((n % 2) == 0)
     {
        for (int i = 0; i < n; i++) 
        {
            data[i] = 'b';
        }
        data[n-1]='a';
    }  
    else 
    {
        for (int i = 0; i < n; i++)
        {
            data[i] = 'a';
        }
    }
    return data;
}


```