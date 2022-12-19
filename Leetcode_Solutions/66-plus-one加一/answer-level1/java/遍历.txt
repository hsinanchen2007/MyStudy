### 解题思路
因为数组的最后一位是个位，所以从个位+1判断是不是10的倍数，如果不是，则该位+1就是该位的结果，因为该位不能进位，
所以之后都不用判断了，如果某一位加1是10的倍数，则该位变为0，计算下一位，如果最高位也变成0时，
证明该数组之前每位都是9，则建立新的数组，并把首位赋值为1即是计算结果

### 代码

```java
class Solution {
    public int[] plusOne(int[] digits) {
       if(digits == null || digits.length <= 0){
            return digits;
        }
        int len = digits.length;
        for (int i = len-1; i >= 0; i--) {
            int num = digits[i]+1;
            if(num%10 > 0){
                digits[i] = num;
                break;
            }else{
                digits[i] = 0;
                if(i == 0){
                    digits = new int[len+1];
                    digits[i] = 1;

                }
            }

        }
        return digits; 
    }
}
```