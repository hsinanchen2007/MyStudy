```
    int a[37];//因为最小和为1 最多为9999->36 故而开大小为37  a[i]表示10进制下和为i的数有几个 
    int countLargestGroup(int n) {
        int res = 0, maxx = 0;
        for(int i = 1; i <= n; i++){
            int j = i, sum = 0;
            while(j) sum += j%10,j/=10;
            maxx = max(maxx,++a[sum]);//求出最多的个数是几
        }
        for(int i = 1; i <= 36; i++)
            if(a[i] == maxx) res++;//统计最大数有几个
        return res; 
    }
```
