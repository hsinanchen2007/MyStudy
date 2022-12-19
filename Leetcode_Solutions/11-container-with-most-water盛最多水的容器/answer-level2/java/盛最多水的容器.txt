### 解题思路
使用两个指针left、right分别指向数组的最左边和最右边
此时计算装水的容量，并和之前的比较，大的保存，小的丢弃；
然后移动较小长度的指针，向中间靠拢。
一直到两个指针相遇，此时退出。

### 代码

```java
class Solution {
    public int maxArea(int[] height) {
        int max = 0;
        int left = 0;
        int right = height.length - 1;
        while(left < right){
            max = Math.max(max, Math.min(height[right], height[left]) * (right- left));
            if(height[right] > height[left]){
                left ++;
            }else{
                right --;
            }
        }
        return max;
    }
}
```