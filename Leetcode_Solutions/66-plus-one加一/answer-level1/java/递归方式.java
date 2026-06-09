### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
        public int[] plusOne(int[] digits) {
            // 最后一位 +1 如果大于10，则改变前一位的值
            return handle(digits, digits.length);
        }

        private int[] handle(int[] digits, int len) {
            // 当要该表的值是第 -1 个元素的时候，表示要在最高位 +1
            if (len == 0) {
                int[] arr = new int[digits.length + 1];
                arr[0] = 1;
                System.arraycopy(digits, 0, arr, 1, digits.length);
                return arr;
            }
            int i = digits[len - 1] + 1;
            if (i >= 10) {
                //改变数组,前一位 +1，当前位取尾数
                digits[len - 1] = i % 10;
                digits = handle(digits, len - 1);
            } else {
                digits[len - 1] = i;
            }
            return digits;
        }
    }
```