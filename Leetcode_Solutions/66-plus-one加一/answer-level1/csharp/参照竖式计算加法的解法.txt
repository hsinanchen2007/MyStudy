参照竖式计算加法的过程，首先定义变量 `temp` 作为进位数，从个位开始计算加一（数组下标对应最后一位），如果有进位，保留计算后的个位（结果%10）、进位数（结果/10）, 并且向上前进一位进行计算（数组下标-1），依次循环；
当1.无进位 2.达到数子最高位 时停止循环，很显然情况1可以直接输出答案，情况2时，那么数字比原来需要额外的一位进制，数组定义好后无法修改长度，则需要新建数组。在本题中限制了加算的值是1，那么直接按照原数组的长度+1新建首个元素值为1的数组即可。


```c#
public class Solution {
    public int[] PlusOne(int[] digits) {
        int temp = 0;
        int i = digits.Length - 1;

        do {
            temp = (digits[i] + 1) / 10;
            digits[i] = (digits[i] + 1) % 10;
            i--;
        } while (temp == 1 && i >= 0);
            
        if(temp == 1){
            int[] result = new int[digits.Length + 1];
            result[0] = 1;
            return result;
        } else {
            return digits;
        }
    }
}
```
