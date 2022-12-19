一上来对0做特殊处理，然后2的指数去遍历，超出x了就对当前指数和前一次指数间的数据做相同的处理，得到结果：
```
 public int  mySqrt(int x) {
        if (x==0) return 0;
        long sum = 0;
        long result = 1;
        while((sum + result)*(sum + result) <= x){
            if ((2*result + sum)*(2*result + sum)>Integer.MAX_VALUE
                    || (2*result + sum)*(2*result + sum)>x){
                sum = sum + result;
                result = 1;
            }else{
                result = 2*result;
            }
        }
        return (int)sum;
    }
```