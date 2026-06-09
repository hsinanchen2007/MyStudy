### 解题思路
1. 数字在 [0, 1] 之间的数只能转化为 1 种字母，数字在 [10. 25] 可以转化成两种字母 比如 10 ：ba or k 这两种
2. 假设数字为 n 位数，如果最后两位在[10， 25] 之前，则总组合个数 = （前 n - 1） + （前 n - 2） 个，否则 总组合个数 = 前 n - 1 个
3. 以此类推，求得最终结果
![image.png](https://pic.leetcode-cn.com/cc4cc2cfdaf505eb02dbb7e61b5450bdff2ccefdbbbcdf3a825c1ded28b4a14f-image.png)

### 代码

```java
class Solution {
    public int translateNum(int num) {
       if(num < 10) {
            return 1;
        }
        if(num < 26) {
            return 2;
        }
        int temp = num % 100;
        if(temp > 9 && temp < 26) {
            return translateNum(num / 100) + translateNum(num / 10);
        }
        return translateNum(num / 10);
    }
}
```