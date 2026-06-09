### 解题思路
此处撰写解题思路

### 代码

```c
int countNumbersWithUniqueDigits(int n){
    if(n==0) return 1;
    if(n==1) return 10;
    int t,s=10,i,j,k;
    for(i=2;i<=n;i++){
        t=9;
        for(j=1,k=9;j<i;j++){
            t*=k;
            k--;
        }
        s+=t;
    }
    return s;
}
```