### 解题思路
- 头尾指针向中间逼近。根据sum的值判断逼近方式
- 初始判断如果头两个数或最后两个数超出边界 那么整个数组一定不符合条件

### 代码

```java
class Solution {
    public int[] twoSum(int[] numbers, int target) {
        int len = numbers.length;
        int[] res = new int[2];
        if (numbers[0] + numbers[1] > target || numbers[len - 1] + numbers[len - 2] < target) {
            return null;
        }
        int i = 0, j = len - 1;
        while (i < j) {
            if (numbers[i] + numbers[j] > target) {
                j--;
            }
            if (numbers[i] + numbers[j] == target) {
                res[0] = i + 1;
                res[1] = j + 1;
                return res;
            }
            if (numbers[i] + numbers[j] < target) {
                i++;
            }
        }
        return null;
    }
}
```