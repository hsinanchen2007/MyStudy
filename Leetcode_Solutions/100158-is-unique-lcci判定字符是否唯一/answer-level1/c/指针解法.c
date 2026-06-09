### 解题思路
暴力扫描，把每一个字符同剩下的所有字符比较，用指针不用另外存储，节省内存

### 代码

```c
bool isUnique(char* astr){
    char *p,*q;
    for(p=astr;*p!='\0';p++){
        for(q=p+1;*q!='\0';q++){
            if(*p==*q){
                 return false;
            }
        }
    }
return true;
}

```