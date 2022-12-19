### 解题思路
哇 我的第一个困难题目 而且一次过了  开心！！！！！！！！！！！！
我们先找到一个最大值的位置（不管有几个最大值，只需要找到一个就好）
找到最大值位置之后，从两边向找到的最大值进行遍历
从左边遍历：
    1 记录一个当前碰到的最大值last，初始为0
    2 height[i]大于这个值，覆盖last的值；小于或等于这个值，那么结果ans就加上last - height[i]
右边遍历是一样的逻辑

![image.png](https://pic.leetcode-cn.com/602e528d505418619743e2996ac71feddf93f0647f551035050d665ba78eaba2-image.png)

### 代码

```java
class Solution {
    public int trap(int[] height) {
        int max = Integer.MIN_VALUE;
        //我这里是记录的最右边的最大值的位置
        int maxValueLastIndex = -1;
        for (int i = 0; i < height.length; i++) {
            if (height[i] >= max) {
                max = height[i];
                maxValueLastIndex = i;
            }
        }
        int last = 0;
        int ans = 0;
        // 从左向右遍历到最大值位置
        for (int i = 0; i < maxValueLastIndex; i++) {
            if (height[i] > last) {
                last = height[i];
            } else {
                ans += last - height[i];
            }
        }
        // 从右向左遍历到最大值位置 记得再次初始化last的值
        last = 0;
        for (int i = height.length - 1; i > maxValueLastIndex; i--) {
            if (height[i] > last) {
                last = height[i];
            } else {
                ans += last - height[i];
            }
        }
        return ans;
    }
}
```