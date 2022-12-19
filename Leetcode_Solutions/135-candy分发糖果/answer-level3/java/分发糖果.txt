### 解题思路
此处撰写解题思路

### 代码

```java
public class Solution {
    public int candy(int[] ratings) {
        int sum = ratings.length;
        int[] left2right = new int[sum];
        int[] right2left = new int[sum];
        for (int i = 1; i < sum; i++) {
            if (ratings[i] > ratings[i - 1]) {
                left2right[i] = left2right[i - 1] + 1;
            }
        }
        for (int i = sum - 2; i >= 0; i--) {
            if (ratings[i] > ratings[i + 1]) {
                right2left[i] = right2left[i + 1] + 1;
            }
        }
        for (int i = 0; i < ratings.length; i++) {
            sum += Math.max(left2right[i], right2left[i]);
        }
        return sum;
    }
}
```