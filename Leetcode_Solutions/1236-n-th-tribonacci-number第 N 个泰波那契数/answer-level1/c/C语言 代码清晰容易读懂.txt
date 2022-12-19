### 解题思路
代码比较清晰。。。

### 代码

```c
int a[100] ;
int trave(int n){
    
    if(a[n] !=NULL) return a[n];

    if(n >= 3)a[n] =  trave(n-1)+trave(n-2)+trave(n-3);
    return a[n];
}
int tribonacci(int n){
    a[0] = 0;
    a[1] = 1;
    a[2] = 1;
    trave(n);
    return a[n];
}
```