### 解题思路
取自大佬：Krahets 的贪心算法，我这里就用java来实现

### 代码

```java
class Solution {

    /**
    * 取自大佬：Krahets 的贪心算法，我这里就用java来实现
    **/
    public int cuttingRope(int n) {
        // 小于等于3的话，那只能分为3 = 1 + 2、2 = 1 + 1
        if (n <= 3) return n - 1;
        // 取3的倍数和余数
        int a = n / 3;
        int b = n % 3;
        // 对余数=1,2,3进行处理
        if (b == 0) return (int) Math.pow(3, a);
        // 3 + 3 + 3 + 1 => 3 + 3 + 2 + 2，最终拿到的值会更大
        if (b == 1) return (int) Math.pow(3, a - 1) * 4;   
        else return (int) Math.pow(3, a) * 2;
    }
}
```