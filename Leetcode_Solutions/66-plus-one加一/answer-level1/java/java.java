### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int[] plusOne(int[] digits) {
        int length = digits.length;
        int i = length-1;
        while (i>-1){
            if (digits[i] == 9){
                digits[i] = 0;
                i--;
            }else {
                digits[i] +=1;
                break;
            }
        }
        if (digits[0] == 0){
            int[] res = new int[length+1];
            res[0] = 1;
            for (int j = 0;j<length;j++){
                res[j+1] = digits[j];
            }
            return res;
        }else {
            return digits;
        }
    }
}
```