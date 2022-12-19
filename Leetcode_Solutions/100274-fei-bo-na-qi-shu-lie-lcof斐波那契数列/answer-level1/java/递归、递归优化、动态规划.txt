递归 (会超时))
```
    public static int fib(int n) {
        if(n==0) return 0;
        if(n==1) return 1;
        return fib1(n-1)+fib1(n-2);
    }
```

递归优化
```
    /*带备忘录的递归算法*/
    public static int fib(int n) {
        int[] arr=new int[101];
        arr[0]=0;
        arr[1]=1;
        fibSolution(arr,n);
        return arr[n];
    }
    public static int fibSolution(int[] arr,int n){
        //退出
        if(n==0) return arr[0];
        if(n==1) return arr[1];

        //查看备忘录,备忘录中没有该记录
        if(n>1 && arr[n]==0)
        arr[n]=(fibSolution(arr,n-1)+fibSolution(arr,n-2))%1000000007;
        return arr[n];
    }
```

动态规划
```
    public static int fib(int n){
        int[] arr=new int[101];
        arr[0]=0;
        arr[1]=1;
        for(int i=2;i<101;i++){
            arr[i]=(arr[i-1]+arr[i-2])%1000000007;
        }
        return arr[n];
    }
```


