### 解题思路
转化为mx+ny=z的数学问题，即x和y的最大公因数可否被z整除。
时间击败100%，空间击败14%

### 代码

```java
class Solution {
    public boolean canMeasureWater(int x, int y, int z) {
        if(z>(x+y)){//针对1 1 12的实例情况，必须满足该条件
            return false;
        }
        if(x==0 && y==0 ){//针对0 0 情况
            if(z==0){//针对0 0 0情况
                return true;
            }else{//针对0 0 1情况
                return false;
            }
        }
        int dmax = gcd(x,y);//取最大公因数
        if(z%dmax == 0){
            return true;
        }else{
            return false;
        }
    }
    int gcd (int m,int n){//最大公因数函数
        if(n==0){
            return m;
        }
        int r = m%n;
        return gcd(n,r);
    }

}
```