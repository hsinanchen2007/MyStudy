


```
/*
[x1,x2] -> [x1,x1+x2] ->[x2,x1+x2] -> [x2,x1]

*/
class Solution {
    public int[] swapNumbers(int[] numbers) {
        numbers[1] = numbers[0] + numbers[1];
        numbers[0] = numbers[1] - numbers[0];
        numbers[1] = numbers[1] - numbers[0];
        return numbers;
    }
}
```
