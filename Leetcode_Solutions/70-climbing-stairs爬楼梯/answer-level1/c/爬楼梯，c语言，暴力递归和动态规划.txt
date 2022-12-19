暴力递归，成功超时 O(2^n)。
//int *p;*p=7;这样不行。因为“能直接给指针指向的数据”赋值，而这里的p还没有指向，所以不能赋值，这种指针有个名字叫“悬浮指针”，是不能给它赋值的。这样才可以：int a,*p=&a;*p=7;
```
void step(int n,int *result){
    if(n>1){
        step(n-2,result);
        step(n-1,result);
    }else if(n>0){
        step(n-1,result);
    }else{
        (*result)++;
    }
}

int climbStairs(int n){
    int result;
    int *p = &result;
    step(n,p);
    return result;
}

```

动态规划-斐波那契数列 O(n)
第n阶可以由  第n-1阶爬一个台阶 和 第n-2阶爬两个台阶    得
res[n] = res[n-1] + res[n-2]
```
int climbStairs(int n){
    if(n<1){
        return 0;
    }
    if(n == 1){
        return 1;
    }
    if(n == 2){
        return 2;
    }
    int a=1,b=2;
    for(int i=0;i<n-2;i++){
        if(a<b){
            a = a+b;
        }else{
            b = a+b;
        }
    }
    return (a>b?a:b);
}
```
