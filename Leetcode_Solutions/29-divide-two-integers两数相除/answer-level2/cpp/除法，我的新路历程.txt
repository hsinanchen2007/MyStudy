# 1.减法暴力
这种算法必定会超时。
```
while(dividend >= divisor){
        dividend -= divisor;
        i++;
    }
```
# 2.指数增长+线性增长
刚开始，除数与商同时指数增长，除数即将超出被除数时，进入线性增长阶段。有点像“TCP拥塞控制”。
这是我开始的做法，但是竟然也超时了！
```
long i=1;
    
        long l = abs(dividend);
        long r = abs(divisor);

        if(l<r)
            return 0;

        long MIN = -(1L<<31);
        long MAX = (1<<31) -1;
        
        long rr ;//指数增长
        for( rr= r;l >= (rr+rr) ;rr = rr+rr){
            i = i+i;
        }
        while (l>= rr+r)//线性增长
        {
            i++;
            rr = rr+r;
        }
        
```
举例 1023 / 2
指数增长阶段算到 512 只需要计算9次，但是后边的 511 仍需要计算511次，只不过比算法1节省了不到一半的时间，O(n/2) = O(n)。

# 3.指数增长，迭代
如果后边511仍然使用指数增长呢？则剩下255。
再对255使用指数增长，剩下127 ...  O(log(n))
```
long k=0;//总计数

        while (l>=r) //l :被除数（迭代后的余数）,左侧的值(left)
        {
            long i=1;//i :阶段商  
            long tmpr = r;//tmpr:阶段除数，r：除数右侧的值（right）

            for ( i = 1; l>= tmpr+tmpr; i+=i,tmpr+=tmpr);

            k+=i;
            l-=tmpr;
        }
```

