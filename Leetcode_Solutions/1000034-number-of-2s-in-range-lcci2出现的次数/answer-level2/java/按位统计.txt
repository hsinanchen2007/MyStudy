### 解题思路
按位统计，双100
![截屏2020-03-28 11.32.52.png](https://pic.leetcode-cn.com/504ad8b36037af776419e2c068c08e0620f291623447fdc65628a9ecd827a692-%E6%88%AA%E5%B1%8F2020-03-28%2011.32.52.png)

### 代码

```java
class Solution {
    public int numberOf2sInRange(int n) {
        int result = 0;
        int l = (n-2) / 10;
        if(l >= 0) result += l+1;
        int base = 1;
        int cp = n / 10;
        while(cp > 0){
            if(n-20*base < 0) break;
            int l1 = (n-20*base) / (100*base);
            int l2 = (n-20*base) % (100*base);
           
            if(l2 >= 10*base) l2 = 10*base-1;
            result += l1*10*base + l2 + 1;
            
            cp /= 10;
            base *= 10;
        }
        return result;
    }

}
```