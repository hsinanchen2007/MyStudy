```
int tribonacci(int n){
    int i;
    if(n == 0) return 0;
    if(n == 1 || n == 2) return 1;  //直接返回就不说了
    long a = 0,b = 0,c = 1,d = 1;
    for(i = 2; i < n; i++) {    //i = 2 从第四项开始
        a = b;      //a => T(n)
        b = c;      //b => T(n+1)
        c = d;      //c => T(n+2)   
        d = a + b + c;  //d => T(n+3)
    }
    return d;
}
```
![捕获.PNG](https://pic.leetcode-cn.com/857de5c41ce8b52f26d672a66e515d27e7507bdba7999cf801df6556ede927ff-%E6%8D%95%E8%8E%B7.PNG)
