### 解题思路
此处撰写解题思路

### 代码

```c
int climbStairs(int n){
    int num=2,i,j=1,tmp;
    if(n==1) num=1;
    else if(n==2) num=2;
    for(i=2;i<n;i++){
        tmp=j;
        j=num;
        num=num+tmp;
    }
    return num;
}
```