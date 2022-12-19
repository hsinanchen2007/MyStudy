### 解题思路
思路比较简单，从1到N所有数换算成二进制字符串后与目标字符串比较，这里调用了strstr函数，若返回NULL则程序结束返回false，否则退出循环返回true。
![image.png](https://pic.leetcode-cn.com/dc2d2e1627385175ee5282a6ec8507ed5818dd0556f99016670c7198b4a86774-image.png)

### 代码

```c
char res[34];
char* str(int x);
bool queryString(char * S, int N){
    int i;
    char *t,*s;
    res[33]='\0';
    for(i=1;i<=N;i++){
        s=str(i);
        t=strstr(S,s);
        if(t==NULL) return false;
    }
    return true;
}
char* str(int x){
    int i=32,t;
    while(x>0){
        t=x%2;
        x/=2;
        res[i--]=t+'0';
    }
    return res+i+1;
}
```