### 解题思路
内存消耗 38.1MB 击败5.07% 有点高 需要优化

### 代码

```java
import java.util.List;
import java.util.ArrayList;
class Solution {
    public int[] plusOne(int[] digits) {
        //实现加1数组函数
        //数组长度1
        int len = digits.length;

        //设置list保存数组值

        //进位值 
        int carry = 1;

        //从右向左遍历
        for (int i = len - 1; i >= 0; i--) {
            int temp = digits[i] + carry;
            if (temp == 10) {
                carry = 1;
                digits[i] = 0;
            } else {
                digits[i] = temp;
                carry = 0;
            }
        }
        
        //需要重新赋值
        if (carry == 1) {
            int[] newArr = new int[len+1];
            Arrays.fill(newArr, 0);
            newArr[0] = 1;
            return newArr;
        } 
            
        return digits;
    }
}
```