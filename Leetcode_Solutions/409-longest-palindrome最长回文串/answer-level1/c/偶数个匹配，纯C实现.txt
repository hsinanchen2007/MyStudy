### 解题思路
我们看这个回文串，只有两种情况，偶数个字母的回文串和奇数个字母的回文串：
1.偶数个字母的回文串，例如abba，原始数组中必然存在两两匹配的字母。
2.奇数个字母的回文串，例如abcba，原始数组中必然存在至少一个字母c作为奇数个存在。
而如果数组中存在奇数个存在的字母，则可以直接添加到回文串的中间位置，其余两两匹配的字母（若存在）则分别添加到中间位置的两端。
以上就是思路。
代码实现也很简单：
（1）开辟一个数组用以保存遍历到、但未发生匹配的字母。
（2）若遍历到的字母在辅助数组中出现过，则发生匹配，将该字母从辅助数组中拿出，字母长度+2；
（3）若遍历完后，辅助数组中仍有字母未发生匹配，则这里面的字母均可以用来做那个奇数个的中间字母，但也仅能选择其中一个，字母长度+1；

### 代码

```c
int longestPalindrome(char * s){
    int sum=0,length=strlen(s);
    char *keep=(char*)malloc(sizeof(char)*(length+1));
    memset(keep,0,sizeof(char)*(length+1));
    int i,j,index=0;
    for(i=0;i<length;i++){
        for(j=0;j<index;j++){
            if(keep[j]=='0')
                continue;
            if(keep[j]==s[i]){
                keep[j]='0';
                sum+=2;
                break;
            }
        }
        if(j>=index)
            keep[index++]=s[i];
    }
    for(i=0;i<index;i++)
        if(keep[i]!='0'){
            sum++;
            break;
        }
    return sum;
}
```