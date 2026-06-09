### 解题思路
此处撰写解题思路

### 代码

```c
bool isSubsequence(char * s, char * t){
    int i,j;
    char *p=s,*q=t;
    if(*s=='\0') return true;
    while(*p!='\0'&&*q!='\0'){
        if(*q==*p){
            q++; p++;
        }
        else q++;
        if(*p=='\0') return true;
    }
    return false;
}
```