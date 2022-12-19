### 解题思路
1. 依次通过 % 得出个位数
2. 然后 n / 10 向右移动一位
3. 乘积 - 求和
![image.png](https://pic.leetcode-cn.com/894279e7fb50115926d4a7b430e4d4c5f49281a7352786ceb30be22821a99d46-image.png)

### 代码

```java
class Solution {
    public int subtractProductAndSum(int n) {
       int multiSum = 1;
       int sum = 0;
       int temp;
       while (n > 0){
           temp = n % 10;
           n /= 10;
           multiSum *= temp;
           sum += temp;
       }
       return multiSum - sum;
    }
}
```