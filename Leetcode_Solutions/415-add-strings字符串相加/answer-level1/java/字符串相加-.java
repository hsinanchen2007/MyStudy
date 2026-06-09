### 题目
给定两个字符串形式的非负整数 num1 和num2 ，计算它们的和。

注意：
1. num1 和num2 的长度都小于 5100.
1. num1 和num2 都只包含数字 0-9.
1. num1 和num2 都不包含任何前导零。
1. 你不能使用任何內建 BigInteger 库， 也不能直接将输入的字符串转换为整数形式。


### 解题思路

### 代码

```java
class Solution {
    public String addStrings(String num1, String num2) {
       int firstRight = num1.length() -1;
       int secondRight = num2.length() -1; 
       int carry = 0;
       char[] array = new char[Math.max(firstRight,secondRight) + 2];
       int idx = array.length - 1;
       while(firstRight >= 0 || secondRight >=0 ) {
           int sum = carry;
           if(firstRight >=0 ) {
               sum += num1.charAt(firstRight)-48;
               firstRight--;
           }
           if(secondRight >=0 ) {
               sum += num2.charAt(secondRight)-48;
               secondRight--;
           }
           array[idx--] = (char)(sum % 10 + 48) ;
           carry = sum / 10;
       }
       if(carry > 0) {
           array[idx] = (char)(carry + 48);
           return new String(array);
       } else {
           return new String(array,1,array.length-1);
       }
       
    }
}
```