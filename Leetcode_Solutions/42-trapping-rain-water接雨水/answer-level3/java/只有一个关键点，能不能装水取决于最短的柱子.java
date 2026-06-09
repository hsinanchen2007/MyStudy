### 解题思路

只有一个关键点，能不能装水取决于最短的柱子

### 代码

```java
class Solution {
    public int trap(int[] height) {
        int length = height.length;
        // 记录最高的柱子，如果有两个相同高度的柱子，那么记录最后一根
        int max = Integer.MIN_VALUE;
        // 最高柱子下标
        int maxflag = -1;

        if (length < 2) {
            return 0;
        }
        for (int i = 0; i < length; i++) {
            if (height[i] >= max) {
                max = height[i];
                maxflag = i;
            }
        }
        // 按照最高柱子将 height 拆成两个数组。preHeight、bottomHeight。
        int[] preHeight = new int[maxflag + 1];
        int[] bottomHeight = new int[length - maxflag];
        // preHeight 是从height的开始位置复制到最高柱子的位置
        System.arraycopy(height, 0, preHeight, 0, maxflag + 1);
        // bottomHeight 是从height的最后位置复制到最高位置。
        for (int j = length - 1, i = 0; j > maxflag - 1; j--, i++) {
            bottomHeight[i] = height[j];
        }
        // 计算积水数量 ，时间复杂度为o(n)
        return getResult(preHeight.length, preHeight)
                + getResult(bottomHeight.length, bottomHeight);
    }

    private int getResult(int length, int[] preHeight) {
        int result = 0;
        int flag = 0;
        if (length <= 1) {
            return result;
        }
        for (int i = 0; i < length; i++) {
            if (flag <= preHeight[i]) {
                flag = preHeight[i];
                continue;
            }
            if (flag == 0) {
                break;
            }
            result += flag - preHeight[i];
        }
        return result;
    }
}
```