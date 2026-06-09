### 解题思路
【曾失败的方案】：循环取出数字+1后输出；遇到的问题：无论用int还是long都会遇到溢出的情况，这种思路不可行
【现有方案】：模拟竖式加法的过程，先对个位数+1，检查是否需要进位；十位、百位……均如此。遇到最极端的“9……999”情形时，则新开数组，最高位（即下标0的）赋值为1，其余默认是0（Java的数组特性所致）

### 代码

```java
class Solution {
    public int[] plusOne(int[] digits) {
        for(int i = digits.length-1;i>=0;i--){
            digits[i] += 1;
            digits[i] = digits[i] % 10;
            if(digits[i] != 0){
                return digits;
            }
        }

        int[] new_digits = new int[digits.length+1];
        new_digits[0] = 1;
        return new_digits;
    }
}
```