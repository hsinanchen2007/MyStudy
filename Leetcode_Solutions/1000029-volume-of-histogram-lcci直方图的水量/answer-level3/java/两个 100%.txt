### 解题思路

用一个数组存 右边最大的数，然后一个for循环 更新左边最大的数

### 代码

```java
class Solution {
    public int trap(int[] height) {
        int n = height.length;
        // int[] left = new int[n];
        // int[] right = new int[n];
        int left = 0;
        int right = 0;

        int[] rightList = new int[n];
        for (int j = n-1;j>=0;j--) {
            right = height[j] > right ? height[j] : right;
            rightList[j] = right;
        }

        int sum =0;
        for (int i =0;i<n;i++) {
            left = height[i] > left ? height[i] : left;
            right = rightList[i];
           sum += (left > right ? right - height[i] : left - height[i]);
        }
        return sum;
    }
}
```