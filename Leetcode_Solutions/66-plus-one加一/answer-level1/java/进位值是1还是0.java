### 解题思路
上一位到当前位的进位要么是0，要么是1。

当且仅当上一位到当前位的进位为1并且当前位是9时，才需要把当前位赋值为0，并且将进位值1继续往高位提交。

只要出现一次进位为0的情况，就可以将当前位的值更新，然后lastExtra永远都是0，digits的更高位也不会更新了，于是直接返回digits。

特殊情况是digits全部为9的情况，也就是遍历完了整个数组，进位值依然为1，需要特殊处理。

### 代码

```java
class Solution {
    public int[] plusOne(int[] digits) {

        int lastExtra = 1;
        for(int i = digits.length-1; i >= 0; i--){
            if(digits[i] == 9 && lastExtra == 1){
                digits[i] = 0;
            } else {
                digits[i] = digits[i] + lastExtra;
                return digits;
            }
        }
        int[] result = new int[digits.length + 1];
        result[0] = 1;
        return result;
    }
}
```