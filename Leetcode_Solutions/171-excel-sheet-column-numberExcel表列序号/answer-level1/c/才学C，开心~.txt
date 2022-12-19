### 解题思路
此处撰写解题思路
![QQ图片20200321180130.png](https://pic.leetcode-cn.com/278a6c287b5a4e9735b2af54b952fdfbc94bad2991567ffa88d66963e0fa608b-QQ%E5%9B%BE%E7%89%8720200321180130.png)

### 代码

```c
#include <math.h>
int titleToNumber(char * s){
    int i,len,pwo;
    int ans=0;
    len=strlen(s);
    for(i=0;i<len;i++){
        pwo=pow(26,len-i-1);
        // printf("%d",s[i]*pwo);
        ans=(s[i]-64)*pwo+ans;
    }
    return ans;
}
```