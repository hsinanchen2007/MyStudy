### 解题思路
利用强制类型转换判断是否发生溢出

### 代码

```c
int reverse(int x){
    long k=0;
    int g;
    while(x){
        g=x%10;
        k=k*10+g;
        x=x/10;
    }
    if(k!=(int)k){
        return 0;
    }else{
        return k;
    }

}
```