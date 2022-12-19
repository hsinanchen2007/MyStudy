```
//定义数组
        int[] a = new int[N+2];
        a[0] = 0;
        a[1] = 1;
        if(N<2) return a[N];
        for(int i=2;i<=N;i++) {
            a[i] = a[i-1]+a[i-2];
        }
        return a[N];
```