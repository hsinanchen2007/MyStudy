### 解题思路
这类问题直接转整数+1一般都会有溢出
所以这里直接使用数组处理+1，  需要注意的点是如9999+1 会变成10000， 这种情况只需要考虑加到最前一位时的进位是否为1即可

### 代码

```java
class Solution {
    public int[] plusOne(int[] digits) {
        // 大数问题，直接数组处理，由于只能存单个数字，处理比较简便
        int length = digits.length;
        if (length == 0 || digits == null) {
            return null;
        }
        int carry = 0;
        for(int i = length-1; i >= 0; i--) {
            if(i == length-1) {
                digits[i] += 1;
            }
            digits[i] = digits[i] + carry;
            if(digits[i] >= 10) {
                digits[i] = 0;
                carry = 1;
            } else {
                carry = 0;
                break;
            }
        }
        // 结果输出
        int[] ans;
        if (carry == 0) {
            ans = new int[length];
            for(int i = 0; i < length; i++) {
                ans[i] = digits[i];
            }
        } else {
            ans = new int[length + 1];
            ans[0] = 1;
            for(int i = 1; i < length + 1; i++) {
                ans[i] = digits[i-1];
            }
        }
        return ans;
    }
}
```