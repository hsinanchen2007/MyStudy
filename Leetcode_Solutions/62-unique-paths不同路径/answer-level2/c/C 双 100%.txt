执行用时 :0 ms, 在所有 C 提交中击败了100.00%的用户
内存消耗 :5.2 MB, 在所有 C 提交中击败了100.00%的用户

return C_(m+n-2)^(m-1) ;

为了算阶乘更快 判断了一下m 和 n 的大小，取其中的小的计算会更快

```
int uniquePaths(int m, int n){
    long int tmp1 = 1;
    long int tmp2 = 1;
    long int i = 0;

    if(m < 2 || n < 2){
        return 1;
    }
    if(m < n){
        for(i = 1; i < m ; ++ i){
            tmp1 *= i; 
        }
        for(i = 0; i < m - 1; ++ i){
            tmp2 *= (n + i);
        }

        return tmp2 / tmp1;
    }else{
        long int tmp = m;
        m = n;
        n = tmp;
        for(i = 1; i < m ; ++ i){
            tmp1 *= i; 
        }
        for(i = 0; i < m - 1; ++ i){
            tmp2 *= (n + i);
        }

        return tmp2 / tmp1;
    }

    
}
```
