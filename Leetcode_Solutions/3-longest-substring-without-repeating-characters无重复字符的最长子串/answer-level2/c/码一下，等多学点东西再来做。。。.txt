### 解题思路
没思路，写了两个子函数：unique_len返回字符串从头数起无重复的长度
                      get_son切割字符串，s[i]到s尾的子串存在a里
遍历s得到所有的子串
1772mshhhhhhhh菜的抠脚
![捕获.PNG](https://pic.leetcode-cn.com/e03398b25889876dfa42d144355dde1171e9613fa7f6ff6a789c68b3a7656508-%E6%8D%95%E8%8E%B7.PNG)

### 代码

```c
int unique_len(char *s){
    int i=0,a[128]={0};
    for(;s[i]!='\0';i++){
        a[s[i]]+=1;
        if(a[s[i]]>1){
            break;
        }
    }
    return i;
}
void get_son(char* s,int i,int len,char* a){
    int j=0;
    for(;i<len;i++){
        a[j]=s[i];
        j++;
    }
}
int lengthOfLongestSubstring(char * s){
    int len=strlen(s),i=0,max=0,temp=0;
    char a[50000]={'\0'};
    for(;i<len;i++){
        get_son(s,i,len,a);
        temp=unique_len(a);
        max=max>temp?max:temp;
        if(len-i+1<=max) break;
    }
    return max;
}
```