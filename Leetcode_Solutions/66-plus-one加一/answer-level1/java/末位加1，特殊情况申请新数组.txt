### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int[] plusOne(int[] digits) {
        int pos = digits.length - 1;
        digits[pos] += 1;
        while(pos >= 0 && digits[pos] >= 10){
            digits[pos--] = 0;
            if(pos < 0){
            int[] newdigits = new int[digits.length+1];
            newdigits[0] = 1;
            for(int i = 1; i < newdigits.length; i++){
                newdigits[i] = 0;
            }
            return newdigits;
        }
            digits[pos] += 1;
        }
        return digits;
    }
}
```