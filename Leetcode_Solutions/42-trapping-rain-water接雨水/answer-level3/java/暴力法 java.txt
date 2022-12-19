### 解题思路
暴力法 java

### 代码

```java
class Solution {
    //暴力法
    public int trap(int[] height) {
        int res = 0;
        for (int i = 0; i < height.length; i++) {
            int left = findLeftMax(i, height);//向左找最大值包括自身
            int right = findRightMax(i, height);//向右找最大值包括自身
            res += Math.min(left, right) - height[i];
        }
        return res;
    }

    private int findRightMax(int i, int[] height) {
        int res = height[i];
        for (int right = i+1; right < height.length; right++) {
            res = Math.max(res, height[right]);
        }
        return res;
    }

    private int findLeftMax(int i, int[] height) {
        int res = height[i];
        for (int left = i - 1; left >= 0; left--) {
            res = Math.max(res, height[left]);
        }
        return res;
    }
}
```