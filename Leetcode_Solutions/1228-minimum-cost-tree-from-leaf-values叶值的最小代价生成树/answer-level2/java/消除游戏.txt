### 解题思路
这题不要把它当成树的题目就好解了，对于每一个最小值我们需要去除它只能是以和当前数据中左右最近的数据乘积作为代价来消除。每一次循环找最小值去除，共需要循环arr.length - 1次。

### 结果
![图片.png](https://pic.leetcode-cn.com/02a51201aaadf91c8b1efe7c43a110e507f9a2737a0c3688ce6b957db4ebf195-%E5%9B%BE%E7%89%87.png)


### 代码

```java
class Solution {
    public int mctFromLeafValues(int[] arr) {
        int result = 0;

        boolean[] taged = new boolean[arr.length];
        for (int i = 0; i < arr.length - 1; i++) {
            int min = Integer.MAX_VALUE;
            int index = -1;
            for (int j = 0; j < arr.length; j++) {
                if (!taged[j] && arr[j] < min) {
                    min = arr[j];
                    index = j;
                }
            }

            int l;
            for (l = index - 1; l >= 0 && taged[l]; l--);
            int leftVal = l < 0 ? Integer.MAX_VALUE : arr[l];
            int r;
            for (r = index + 1; r < arr.length && taged[r]; r++);
            int rightVal = r >= arr.length ? Integer.MAX_VALUE : arr[r];
            result += Math.min(leftVal, rightVal) * arr[index];

            taged[index] = true;
        }

        return result;
    }
}
```