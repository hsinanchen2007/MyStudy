### 解题思路
（1）处理特殊情况
（2）找到h与n字符相同的位置，记录下此刻的位置k
（3）从k开始找h与n相同的字符，若相同的字符数等于n的字符串长度，返回k
（4）若不相等，从k开始重复（2），(3)步，直到结尾。

### 代码

```c
int strStr(char * haystack, char * needle){
    int i=0,n,m,j=0,k;
    n=strlen(haystack);
    m=strlen(needle);
    if(m>n) return -1;
    if(m==0||n==0) return 0;
    if(needle==haystack) return 0;
    
    for(i=0;i<n;i++){
        j=0;
        while(i<n&&haystack[i]!=needle[j]){
            i++;
        }
        if(n-i<m) return -1;//h余下字符串的长度小于n的字符串的长度
        k=i;//记录下第一个相同字符的位置，用于返回或下次循环i的取值
        while(i<n&&haystack[i]==needle[j]){
            i++;
            j++;
        }
        if(j==m) return  k;//如果相同字符的个数为n的长度，返回k
        i=k;
    }
    return -1;
    
}


```