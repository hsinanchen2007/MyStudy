![QQ截图20200308005911.png](https://pic.leetcode-cn.com/70e34f4a02c02ccba7ac611af6e4f511b379462aaf5d32a3c5a6ed808067b5d7-QQ%E6%88%AA%E5%9B%BE20200308005911.png)
### 解题思路
（1）定义int数组存每个字母的个数。
（2）从a-z顺序，顺序i=0:25，如果存在这个字母CNT[S[i]]>0,就可以把这个字母按顺序存到元字符串当中。
（3）z-a就可以i=25：0依次把存在的字母放进元数组。
重复（2）-（3）。
直到i == strlen。重组字符串结束。

### 代码

```c


char * sortString(char * s){
    int* cnt = (int*)malloc(sizeof(int)*26);
    memset(cnt,0,sizeof(int)*26);
    int len = strlen(s);
    int i = len,j=0;
    while(i--)  cnt[ s[i] - 'a']++;
    for(i = 0;i<len;){
        for(j = 0 ; j<26&&i<len ; j++){
            if(cnt[j]>0){
                s[i++] = 'a' + j;
                cnt[j]--;
            }
        }
        for(j=25 ; j>=0 && i<len ; j--){
            if(cnt[j]>0){
                s[i++] = 'a' + j;
                cnt[j]--;
            }
        }
    }
    return s;
}


```