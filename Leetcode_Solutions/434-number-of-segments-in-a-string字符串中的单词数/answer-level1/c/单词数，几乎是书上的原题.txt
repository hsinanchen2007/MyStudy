### 解题思路
增加flag标志，若当前字符为非空格，且前一个字符为空格，表示新单词出现

### 代码

```c
int countSegments(char * s){
    int i,sum,flag;
    i=sum=flag=0;
    for(;s[i]!='\0';i++){
        if(s[i]==' ')flag=0;
        else if(flag==0){
            sum++;
            flag=1;
        }
    }
    return sum;
}
```