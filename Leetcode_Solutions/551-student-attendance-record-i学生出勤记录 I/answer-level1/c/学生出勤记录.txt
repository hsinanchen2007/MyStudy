### 解题思路
调用3个函数即可
strstr()    //判断'LLL'是否出现
strchr()    //记录'A'第一次出现的位置
strrchr()   //记录'A'最后一次出现的位置

### 代码

```c
bool checkRecord(char * s){
    char *a1,*a2,*l1;
    a1=strchr(s,'A');
    a2=strrchr(s,'A');
    l1=strstr(s,"LLL");
    if(a1!=NULL&&(a1!=a2)||l1)  //排除'A'一次都未出现的情况
        return false;
    return true;
}
```