### 解题思路
笨方法，转化为二进制，再检查即可

### 代码

```c
bool hasAlternatingBits(int n){
    char res[100]="";
    int i=0;
    while(n){
        res[i++]=n%2+'0';
        n/=2;
    }
    res[i]='\0';
    for(int j=0;j<i-1;j++){
        if(res[j]==res[j+1])
            return false;
    }
    return true;
}
```