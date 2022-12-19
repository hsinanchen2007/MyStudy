### 解题思路

在确定拆分成多少段后，由数学知识可知，乘积最大时肯定需要更均分的切，故易求得固定分的段数的最大乘积
而最终的乘积可看成是分成段数的一个函数，此函数易知先增后减，故只需要求出最大值即可。

### 代码

```java
class Solution {
    public int cuttingRope(int n) {
    int i=2,product=0,temp=0;
        while (i<=n) {
            temp=product;
            product = product(n, i);
            i++;
            if (temp > product) {
                return temp;
            }
        }
        return product;
    }
    private  int product(int n, int i) {
            int count=n%i;
            int av=n/i;
            int sum=1;
        for (int j = 0; j < i; j++) {
            if (count != 0) {
                sum *= (av + 1);
                count--;
            } else {
                sum*=av;
            }
        }
        return sum;
    }
}
##### ```