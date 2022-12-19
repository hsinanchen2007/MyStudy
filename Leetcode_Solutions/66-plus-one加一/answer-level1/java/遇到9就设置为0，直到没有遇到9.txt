### 解题思路
从低位开始遍历，遇到9就设置为0，直到没有遇到9的情况，就加上1然后返回。

特殊情况是digits全部为9的情况，也就是遍历完了整个数组，进位值依然为1，需要特殊处理。

### 代码

```java
class Solution {
    public int[] plusOne(int[] digits) {
        for(int i = digits.length-1; i >= 0; i--){
            if(digits[i] == 9){
                digits[i] = 0;
            } else {
                digits[i] = digits[i] + 1;
                return digits;
            }
        }
        int[] result = new int[digits.length + 1];
        result[0] = 1;
        return result;
    }
}
```