### 解题思路
使用数据类型long可以避免运算过程中的溢出问题，在最后return时强制转换数据类型，由于之前有溢出判断，所以不用担心强制转换数据类型会造成溢出。

### 代码

```java
class Solution {
    public int reverse(int x) {
        long num = Math.abs(x);
        long res = 0;
        while (num > 0){
            res = res * 10 + num % 10;
            if (res > Math.pow(2,31) - 1){
                return 0;
            }
            num = num / 10;
        }
        return x > 0 ? (int)res : (int)-res;
    }
}
```