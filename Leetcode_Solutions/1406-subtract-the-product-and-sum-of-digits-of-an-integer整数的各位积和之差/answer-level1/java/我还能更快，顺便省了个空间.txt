### 解题思路
冲冲冲！
1乘任何数都是任何数，0加任何数都是任何数。
直接用取模的结果来*=或者+=过去，还能省一个空间


### 代码

```java
class Solution {
    public int subtractProductAndSum(int n) {
        int product=1, sum=0;
        while(n>0){
            product *= (n%10);
            sum += (n%10);
            n/=10;
        }
        return product-sum;        
    }
}
```