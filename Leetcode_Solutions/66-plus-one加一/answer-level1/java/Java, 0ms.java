### 解题思路
最重要的是进位的问题

### 代码

```java
class Solution {
    public int[] plusOne(int[] digits) {
        int len = digits.length;
        for (int i = len-1; i > -1 ; i--) {
            digits[i] = digits[i] + 1;
            if (digits[i]<10) {  // 没有进位直接返回
                return digits;
            } else {             // 进位则当前位为0，继续循环
                digits[i] = 0;
            }
        }
        if (digits[0] > 0) {
            return digits;
        } else {
            // 全部进位则要新建数组
            int[] answer = new int[len + 1];
            answer[0] = 1;
            for (int i = 1; i < len + 1; i++) {
                answer[i] = 0;
            }
            return answer;
        }
    }
}
```