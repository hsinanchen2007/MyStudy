### 解题思路
对于指针使用的不好，所以使用的最原始的标记，已经找到了一个指针扫描的算法列入学习目标中。

### 代码

```c
int strStr(char * haystack, char * needle){
    int i,j,k,count,post;
    int lenh=strlen(haystack);
    int lenn=strlen(needle);
    if(lenn==0) return 0;
    if(lenh==0) return -1;
    for(i=0;i<lenh&&count<lenn;i++){
        post=i;
        k=i;
        count=0;
        if((lenh-i)<lenn) return -1;
        for(j=0;j<lenn&&count<lenn;j++){
            if(haystack[k]==needle[j]){
                ++k;
                ++count;
            }
        }
    }
    if(count==lenn)    return post;
    else return -1;

}
```
### 总结
1、没有判定空数组的时候如何返回，这导致空数组出现错误的返回结果。
2、无论如何修改，都会超出时间限制，仔细想了一下，当h数组中剩下的未匹配的元素个数少于n中的元素的个数的时候，就可以退出了。加上这条判定语句之后果然通过了。开心！
3、像Knight致敬加学习！人家都只睡七个小时！！然后一直训练！！！