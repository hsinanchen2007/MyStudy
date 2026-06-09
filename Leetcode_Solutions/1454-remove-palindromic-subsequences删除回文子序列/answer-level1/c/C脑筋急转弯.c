### 解题思路
![Snipaste_2020-03-22_15-12-01.png](https://pic.leetcode-cn.com/53dbfe33da241d42763298317f0d72b7a0a7cffc49e1b2d95297a5cb67381d17-Snipaste_2020-03-22_15-12-01.png)
注意是子序列而非子串，意味着可以跳着选，那么要么整个是回文串，一次即可，要么第一次把所有a取出来，剩下全是b，第二次取完。

### 代码

```c
int removePalindromeSub(char * s){
    int len=strlen(s);
    if(len==0) return 0;
    if(len==1) return 1;
    int low=0,high=len-1;
    while(low<high){
        if(s[low]!=s[high])
        return 2;
        low++;
        high--;
    }
    return 1;
}
```