 **思路**   
#### 用一个while循环判断num是1跳出循环，循环内部用2，3，5整除，可被整除就将num用整除后的模覆盖继续循环，如果2，3，5都不是被除数，在循环内部直接返回false。正常循环结束，则可以判断该数是丑数。
例如：
![微信截图_20190717140019.png](https://pic.leetcode-cn.com/e3b91a3914914ea32dabb50d1642dd1b0c1275be915d4052dff940b261a0f9fe-%E5%BE%AE%E4%BF%A1%E6%88%AA%E5%9B%BE_20190717140019.png)

```java []
 public boolean isUgly(int num) {
        if(num<=1)return false;
        int mod = 0;
        int last = num; //余数
        while(num!=1) {
            mod = num / 2;
            last = num % 2;
            if (last != 0) {
                mod = num / 3;
                last = num % 3;
                if (last != 0) {
                    mod = num / 5;
                    last = num % 5;
                    if (last != 0) {
                        return false;
                    }else{
                        num = mod;
                    }
                }else{
                    num = mod;
                }
            }else{
                num = mod;
            }
        }
            return  true;
    }
```

