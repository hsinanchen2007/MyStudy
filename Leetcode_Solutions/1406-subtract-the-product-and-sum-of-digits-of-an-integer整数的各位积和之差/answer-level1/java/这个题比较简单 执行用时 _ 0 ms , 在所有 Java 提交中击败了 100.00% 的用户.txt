### 解题思路
一个while循环，分别乘以和加上n%10的余数，最后相减。

### 代码

```java
class Solution {
    public int subtractProductAndSum(int n) {
        int multiple = 1,sum = 0;
        while(n > 0){
            sum += n%10;
            multiple *= n%10;
            n -= n%10;
            n /=10;
        }
        return multiple - sum;
    }
}
```