### 解题思路
一次计算每位的aliquant的数字即可，思路简单

### 代码

```java
class Solution {
    public int subtractProductAndSum(int n) {
        int productResult=1;
        int sumResult=0;
        while(n!=0){
            int aliquant=n%10;
            productResult*=aliquant;
            sumResult+=aliquant;
            n=n/10;
        }
        return productResult-sumResult;
        
    }
}
```