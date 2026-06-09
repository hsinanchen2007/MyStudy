### 解题思路


### 代码

```c
int climbStairs(int n){
    int *a,i;
    a=(int*)malloc(sizeof(int)*n);
    for(i=0;i<n;i++){
        if(n>0&&n<4){ 
            return n;
        }
        else if(i>2)
        {
            a[1]=2;
            a[2]=3; 
            a[i]=a[i-1]+a[i-2];
        }
    }
    i=a[n-1];
    free(a);
return i;
}
```