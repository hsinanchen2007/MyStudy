### 解题思路
使用两个指针，顺序扫描比较是否有相同字符

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