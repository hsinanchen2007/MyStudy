![捕获.JPG](https://pic.leetcode-cn.com/19ce031ebe962443e57e0964f91cb222741fca4d7c3d4c2650d596a92df2b04e-%E6%8D%95%E8%8E%B7.JPG)

### 解题思路
此题思路是在参考了
[https://leetcode-cn.com/problems/greatest-common-divisor-of-strings/solution/1071-zi-fu-chuan-de-zui-da-gong-yin-zi-by-wonderfu/]()
![捕获.JPG](https://pic.leetcode-cn.com/2dfbf8f3dcf14b6932af70427049081984f97d5cf6d6aa8e143ba7f217d4a3d6-%E6%8D%95%E8%8E%B7.JPG)
的思路之后用C语言进行改写的。
（位置在题解中按JavaScript搜索的第一条）

最主要思路为：
如果字符串*S*和字符串*T*都是由字符串X拼接而成，那么*S+T*和*T+S*应该是相同的；
并且X的长度应该是*S*和*T*长度的最大公约数。
详细思路请移步上述链接

### 代码

```c
//求最大公约数
int gcd(int l1, int l2){
    if(l2==0)
        return l1;
    else
        return gcd(l2,l1%l2);
}


char * gcdOfStrings(char * str1, char * str2){
    char *tmp1=(char *)calloc(strlen(str1)+strlen(str2)+2, sizeof(int));
    char *tmp2=(char *)calloc(strlen(str1)+strlen(str2)+2, sizeof(int));

    strcpy(tmp1,str1);
    strcat(tmp1,str2);
    
    strcpy(tmp2,str2);
    strcat(tmp2,str1);
    //查看str1+str2 是否等于 str2+str1
    if(strcmp(tmp1,tmp2)!=0)
        return "";
    
    int len1=strlen(str1), len2=strlen(str2);
    int len=gcd(len1,len2);
    
    return str1+len1-len;



}
```