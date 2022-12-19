### 解题思路
代码很简单，就不说了

### 代码

```java
class Solution {
    public int[] swapNumbers(int[] numbers) {
        numbers[0] = numbers[0] - numbers[1];
        numbers[1] = numbers[1] + numbers[0];
        numbers[0] = numbers[1] - numbers[0];
        return numbers;

    }
}
```