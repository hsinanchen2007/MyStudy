### 解题思路
不需要考虑numbers[i]=numbers[j]的情况，因为题目给了只有唯一答案就不能重复。

那么numbers = [1,4,5,5,6,7],targer = 10的情况只可能i=4,j=6。

### 代码

```java
class Solution {
    public int[] twoSum(int[] numbers, int target) {
        int i = 0;
        int j = numbers.length - 1;
        while (i < j) {
            int total = numbers[i] + numbers[j];
            if (total > target) {
                j--;
            } else if (total == target) {
                return new int[] {i + 1, j + 1};
            } else if (total < target) {
                i++;
            }
        }
        return new int[] {i + 1, j + 1};
    }
}
```