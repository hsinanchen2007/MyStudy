### 解题思路
此处撰写解题思路

### 代码

```c
long reverse(long x){
    int flag=1;
    if(x<0){
        x=(-x);
        flag=-1;
    }
    long y=0;
    while(x>0){
       y*=10;
       y+=x%10;
       x=x/10;
       if(y!=(long)(int)y){
           y=0;
           break;
       }
    }
    //y+=x;
    y*=flag;
    return y;
}
```