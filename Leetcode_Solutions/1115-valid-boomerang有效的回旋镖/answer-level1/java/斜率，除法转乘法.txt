### 解题思路
只是3个点的话就只用处理每两个点之间的斜率问题，但是由于计算时会出现差为0的情况，所以原来的除法结果最好转化成乘法结果来比较。

![image.png](https://pic.leetcode-cn.com/15195b4bf6f9a045c625933a4acaa89ddbe7318d630231274a90d105eb033e53-image.png)

### 代码

```java
class Solution {
    public boolean isBoomerang(int[][] points) {
        return (points[1][1] - points[0][1]) * (points[2][0] - points[1][0]) !=
                (points[2][1] - points[1][1]) * (points[1][0] - points[0][0]);
    }
}
```