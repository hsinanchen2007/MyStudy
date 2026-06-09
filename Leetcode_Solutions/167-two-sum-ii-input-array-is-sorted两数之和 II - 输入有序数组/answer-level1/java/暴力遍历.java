### 解题思路
双重for循环遍历所有组合，复杂度为O(n^2)

### 代码

```java
class Solution {
    public int[] twoSum(int[] numbers, int target) {
        if (numbers == null) {
            return null;
        }
        for (int i = 0; i < numbers.length - 1; ++i) {
            for (int j = i + 1; j < numbers.length; ++j) {
                if (numbers[i] + numbers[j] == target) {
                    int[] result = new int[]{i + 1, j + 1};
                    return result;
                }
            }
        }
        return null;
    }
}
```