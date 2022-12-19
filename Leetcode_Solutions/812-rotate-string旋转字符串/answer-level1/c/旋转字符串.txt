### 解题思路
先将B复制两次放在新字符串res中，再使用strstr()函数，看res中是否存在A

### 代码

```c


bool rotateString(char * A, char * B){
    int len_A=strlen(A),len_B=strlen(B);
    if(len_A!=len_B) return false;
    char *res=(char*)malloc(sizeof(char)*(2*len_B+1));
    res[2*len_B]='\0';
    strcpy(res,B);
    strcat(res,B);
    if(strstr(res,A)==NULL) return false;
    return true;
}


```