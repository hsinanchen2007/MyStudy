### 解题思路
同样的算法多提交几次，有惊喜！！！
![1584074445(1).png](https://pic.leetcode-cn.com/e76bbdfb6e685f5c4205e8a0b480c328aa2736d0e6001b7fd56dec1fe0948d4d-1584074445\(1\).png)

### 代码

```c
char * generateTheString(int n)
{
    char *ret;
    ret=(char *)malloc(sizeof(char)*(n+1));
    ret[n]='\0';
    memset(ret,'b',n);
    ret[n-1]='b'+(n%2==0);
    return ret;
}
```