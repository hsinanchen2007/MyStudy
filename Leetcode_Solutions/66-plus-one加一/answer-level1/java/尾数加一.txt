### 解题思路
1. 变量p保存进位值，默认为1就等于题目要求的+1；
2. 从结尾开始循环，当前结果等于 当前+p 的值；
3. +p后判断是否大于10，如果小于那么p=0; 如果大于那么p=1，且当前值=0；
4. 如果遍历完毕进位不为0， 比如 999 或99 情况，且一定为n个9的情况，因为只有n个9才会+1导致数组位数变化。
5. n个9 再+1，必然等于一个+1长度的数组，首位为1即可。
### 代码

```java
class Solution {
    public int[] plusOne(int[] digits) {
        int p = 1;
        for (int i = digits.length - 1; i >= 0; i--){
            int num = digits[i] + p;
            if (num < 10){
                digits[i] = num;
                p = 0;
            }else
            {
                digits[i] = 0;
                p = 1;
            }
        }
        if (p > 0){
            digits = new int[digits.length + 1];
            digits[0] = p;
        }
        return digits;
    }
}
```