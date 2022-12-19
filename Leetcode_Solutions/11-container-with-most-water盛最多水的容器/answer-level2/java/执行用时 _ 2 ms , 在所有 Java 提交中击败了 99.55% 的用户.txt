### 解题思路
双指针。
相比于官方的双指针题解方法，
唯一优化的地方是：将较短的垂线向内移动时，对下一条垂线进行判断，如果不大于当前的垂线，则继续移动，而不进行计算；
理由：向内移动，宽度缩短，若较短的一边垂线没有增加，容积是不会增大的。


### 代码

```java
class Solution {
    public int maxArea(int[] height) {
        int result = 0;
        int head = 0;
        int rear = height.length - 1;
        int left = height[head];
        int right = height[rear];

        while(head < rear) {
            int len = rear - head;
            int high = Math.min(left, right);
            result = Math.max(result, len * high);
            if(left < right) {
                do {
                    head++;
                } while(head < rear && left >= height[head]);
                left = height[head]; 
            } else {
                do {
                    rear--;
                } while(head < rear && right >= height[rear]);
                right = height[rear];
            }
        }
        return result;
    }
}
```