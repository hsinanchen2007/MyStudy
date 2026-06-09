### 解题思路
传入的字符串是一个常量字符串，要自己新建立一个字符串进行返回，不能直接修改S指向的字符串。
### 代码

```c
char* reverseLeftWords(char* s, int n){
//测量一下S指向的字符串有几个字符（不包含末尾的'\0'）
    int length=0;
    while(s[length]!='\0')
        ++length;
//生成新的字符串（注意要给末尾的'\0'申请空间）
    char *temp=(char*)malloc(sizeof(char)*(length+1));
//首先把左边起第n+1个字符到最后一个字符移动到新字符串
    int i=n,j=0;
    while(s[i]!='\0')
        temp[j++]=s[i++];
//其次把左边起第1个字符到第n个字符接入新字符串末尾
    for(i=0;i<n;++i)
        temp[j++]=s[i];
//最后一个'\0'补在新字符串末尾
    temp[j]='\0';
//返回新字符串地址
    return temp;
}
```