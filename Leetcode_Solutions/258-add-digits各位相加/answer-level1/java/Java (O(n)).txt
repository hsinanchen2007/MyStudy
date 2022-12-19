### 解题思路
正常的循环思路。个人觉得那个数学魔幻算法很难在面试中复现。

### 代码

```java
class Solution {
    public int addDigits(int num) {
        while (num > 9){
            num = digitAdder(num);
        }
        return num;
    }

    public int digitAdder(int n){
        int res = 0;
        while (n > 0){
            res += n % 10;
            n = n / 10;
        }
        return res;
    }
}
```