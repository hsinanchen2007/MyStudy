### 解题思路
这个题目的打法拆分成两个部分；
1、用i和j锁定单词的首尾
2、用revers对s[i]到s[j]进行翻转
3、反复执行1、2直到遍历完字符串结束。
### 代码

```c
void revers(char *s,int i,int j){
    char temp;
    while(i<j){
        temp=s[i];
        s[i]=s[j];
        s[j]=temp;
        i++;j--;
    }
}
char * reverseWords(char * s){
    int i=0,j=0;int slen=strlen(s);
    for(int n=0;n<slen;n++){
        if(s[n]!=' '){
            i=n;n++;
            while(s[n]!='\0'&&s[n]!=' '){
                n++;
            }
            j=n-1;
            revers(s,i,j);
        }
    }
    return s;
}
```