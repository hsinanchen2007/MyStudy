### 解题思路
想要容纳最多的水，可以理解为需要尽量大的高度，和尽量大的宽度的乘积。
我们假设已有选择了左右两侧的垂直线，那么可以反向推理：
1.一定不存在比左侧垂线高的线，在左侧垂线的 左边；
2.一定不存在比右侧垂线高的线，在右侧垂线的右边；
否则，可以选择以上两种情况的线，获取到可以容纳更多水的容器。

那么，我们设置头尾指针，分别指向左右两侧尽量高的垂线，
先固定左侧线，从数组头开始：
1.遇到 <= 当前左测线高度的，直接跳过；
2.遇到 > 当前左测线高度的，进入右侧线判断：
    从数组最右开始确定右侧线：
    1. 遇到 <= 当前右测线高度的，直接跳过；
    2. 遇到 > 当前右测线高度的，开始计算左右两侧线固定后，能容纳的水的大小，记录最大值。
    3. 当左右侧线相遇时，跳出；
3.到数组尾，结束。


### 代码

```java
class Solution {
    public int maxArea(int[] height) {
        int head = 0;
        int len = height.length;
        int result = 0;
        int leftHigh = 0;

        while(head < len) {
            if(height[head] <= leftHigh) {
                head++;
                continue;
            }

            leftHigh = height[head];
            int rear = len - 1;
            int rightHigh = 0;
            while(head < rear) {
                if(height[rear] <= rightHigh) {
                    rear--;
                    continue;
                }
                rightHigh = height[rear];
                result = Math.max(result, Math.min(rightHigh, leftHigh) * (rear - head));
                rear--;
            }
            head++;
        }
        return result;
    }
}
```