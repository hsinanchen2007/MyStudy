### 解题思路
先考虑正常的情况：字符串里有单词
j 从串尾向前遍历找到第一个不是空格的字符
i 从j 的前一个开始向前遍历，直到空格，或者到s[0]了也不是空格，让i 自减成-1，退出
j 是单词的尾巴，i 是单词的“帽子”，帽子要么是空格，要么是s[0]之前的一个“虚拟帽子”
返回j - i 就是单词的长度了
然后排除掉空串和一堆空格的表面字符串
### 代码

```c
int lengthOfLastWord(char * s){
    int i=0,j=strlen(s)-1,flag=0;
    for(i=0;i<=j;i++){
        if(s[i]!=' '){
            flag=1;
            break;
        }
    }
    if(!flag||j<0) return 0;
    while(s[j]==' '){
        j--;
    }
    for(i=j-1;i>=0;i--){
        if(s[i]==' ') break;
    }
    return j-i;
}
```