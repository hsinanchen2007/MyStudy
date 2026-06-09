### 解题思路
不用临时变量，双100%

### 代码

```java
class Solution {
    public int[] swapNumbers(int[] numbers) {
        numbers[0] -= numbers[1];
		numbers[1] += numbers[0];
		numbers[0] = numbers[1] - numbers[0];
		return numbers;
    }
}
```