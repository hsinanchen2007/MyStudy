### 解题思路
直接看代码就行，超级简单

### 代码

```java
class Solution {
    public int[] plusOne(int[] digits) {
        int carry = 0;
        int[] result = new int[digits.length + 1];
        int j = result.length-1;
        for (int i = digits.length-1; i >= 0; i--) {
            int p = digits[i];
            if (i == digits.length-1) {
                p += 1;
            } else {
                p = p + carry;
            }
            if (p >= 10) {
                carry = 1;
                p -= 10;
            } else {
                carry = 0;
            }
            result[j] = p;
            j--;
        }
        if(carry == 1){
            result[j] = 1;
            return result;
        }else{
            return Arrays.copyOfRange(result,1,result.length);
        }
    }
}
```