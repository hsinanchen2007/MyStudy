# 其实递归挺简单的，代码中两个注释就能解释代码了
```java
class Solution {
    int count = 0; // 记录递归的次数
    public int[] plusOne(int[] digits) {
        int len = digits.length - count++; // 当前列表长度
        if (digits[len-1] != 9) digits[len-1] += 1;
        else {
            while (len-1 > 0) {
                digits[len-1] = 0;
                return plusOne(digits);
            }
            // 如果递归到数组中第一个元素仍为9，那么就只有一种情况，需要开辟新的数组例如[9,0,0] --> [1,0,0,0]
            digits = new int[digits.length + 1]; 
            digits[0] = 1;
            return digits;
        }
        return digits;
    }
}
```
