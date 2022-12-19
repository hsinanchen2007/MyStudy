### 解题思路
双百。。虽然我也知道我的代码不好看

### 代码

```c
int tribonacci(int n){
    if(n==0){//T0==0
        return 0;
    }
    if(n<3){// T1==1&&T2==1;
        return 1;
    }
    int t0=0,t1=1,t2=1,tn;
    while(n>2){
        tn=t0+t1+t2;
        t0=t1;t1=t2;t2=tn;
        n--;
    }
    return tn;
}
```