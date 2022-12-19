### 解题思路
快慢指针，sum 小于 target ，快指针向右移动。等于时慢指针为起始值，快指针为终止值。大于 target 快指针向右移动。

### 代码

```java
class Solution {
    public int[][] findContinuousSequence(int target) {
        List<int[]> list = new ArrayList<>();
        int length = target / 2 + 1;
        for (int i = 1; i < length; i++) {
            int j = i;
            int sum = i;
            while (sum < target) {
                ++j;
                sum = sum + j;
            }
            if (sum == target) {
                int[] arr = new int[j - i + 1];
                for (int a = 0; a < j - i + 1; a++) {
                    arr[a] = i + a;
                }
                list.add(arr);
            }
        }
        return list.toArray(new int[0][]);
    }
}
```
![image.png](https://pic.leetcode-cn.com/e800929777a7e22d7fc0a3748b37f64dc55ab0aefbbbb23cfe9edfcdd7139273-image.png)
