### 解题思路
记录每个位的值，能进位就进位
若99，999这种情况就new int进位

### 代码

```java
class Solution {
    public int[] plusOne(int[] digits) {
        int digits_len = digits.length;
        int flag = 0,temp = 0;
        for(int i=digits_len-1;i>=0;i--){
            if(flag>0){
                temp = digits[i] + flag;
                flag = 0;
            }else {
                temp = digits[i] + 1;
            }
            if(temp>9){
                flag=1;
                digits[i] = 0;
            }else {
                digits[i] = temp;
                break;
            }
        }
        if(flag==1){
            digits = new int[digits_len+1];
            digits[0] = 1;
        }
        return digits;
    }
}
```