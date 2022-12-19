使用异或不会有溢出现象
```
class Solution {
    public int[] swapNumbers(int[] numbers) {
        numbers[0] ^= numbers[1]; // {a^b, b}
        numbers[1] ^= numbers[0]; // {a^b, a}
        numbers[0] ^= numbers[1]; // {b, a}
        return numbers;
    }
}
```
