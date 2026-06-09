### 解题思路
![image.png](https://pic.leetcode-cn.com/4156b9ff73fa8022229c95af0edc388ecef10cb0773485b4f46e00c7c7972538-image.png)


### 代码

```c
char* reverseLeftWords(char* s, int n){
    int len = strlen(s);
    char *ans  = (char *)calloc(len*2+1,sizeof(char));

    strcpy(ans,s);
    strncat(ans,s,len);
    ans[len+n]='\0';

    return ans+n;

}
```