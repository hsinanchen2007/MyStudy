### 解题思路
原来这是一个规律题
解题关键在于：子序列可以不连续！！！！
所以如果字符串本身不是回文的话，只需要先删所有的a，在删所有的b，操作2次即可；
如果本身就是回文，就操作1次
如果字符串为0，就操作0次
### 代码

```c
int removePalindromeSub(char * s){
    if(strlen(s)==0)return 0;
    int i=0,j=strlen(s)-1;
    while(i<j){
        if(s[i]!=s[j])return 2;
        i++;
        j--;
    }
    return 1;

}
```