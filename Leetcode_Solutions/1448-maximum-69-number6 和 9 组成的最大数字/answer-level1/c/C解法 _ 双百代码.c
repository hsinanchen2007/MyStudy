### 解题思路


### 代码

```c
int maximum69Number (int num){
    int k=1;
    int nc=num;
    while(nc!=0)
    {
        k=k*10;
        nc=nc/10;
    }
    k=k/10;
    nc=num;
    while(k!=0)
    {
        if(nc/k==6)
        {
            num+=3*k;
            break;
        }
        nc=nc-9*k;
        k=k/10;
    }
    return num;
}
```