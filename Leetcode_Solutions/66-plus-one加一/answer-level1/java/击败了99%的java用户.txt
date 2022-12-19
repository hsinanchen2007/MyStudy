## 解析
从右向左，只要有一位没有进位。那后面的都不会有进位。
还有比如999这种情况，最后的结果为10000。只需要新建一个比当前数组大1位的数组。并且0位置为1即可。
## 代码
```java
public int[] plusOne(int[] digits) {
        for (int i = digits.length - 1; i >= 0; i--) {
            digits[i]++;
            digits[i] = digits[i] % 10;
            if (digits[i] != 0){
                return digits;
            }
        }
        digits = new int[digits.length + 1];
        digits[0] = 1;
        return digits;
    }
```

