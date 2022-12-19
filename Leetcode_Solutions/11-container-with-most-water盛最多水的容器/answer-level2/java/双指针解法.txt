### 解题思路
此处撰写解题思路
1. 使用两个指针分别从左右开始，设左指针为L，右指针为R,则面积等于Min(H[L],H[R])*(R - L),故决定面积的因素为左右两边的最小值、（R - L）.所以在H[L] < H[R]时 L右移，反之则R左移，这样便能找到最大值了。

### 证明
当H[L] < H[R] 时，此时面积由H[L]决定，倘若L左移是漏掉最大值，左移时跳过了Min(H[L],H[R])*(R - L)的最大值，若此时的最大值是在L位置的左边，代表已经计算过了，做在L的左边（左移的时候R - L 必定减小，这是不可避免的），这就是现在正在计算的，所以不会漏掉。H[R] >= H[L] 的情况相似。 

### 代码

```java
class Solution {
    public int maxArea(int[] height) {
        int maxArea = 0;
        int l = 0, r = height.length - 1;
        while (l < r) {
            maxArea = Math.max(maxArea, Math.min(height[l], height[r]) * (r - l));
            if (height[l] < height[r]) {
                l++;
            } else {
                r--;
            }
        }
        return maxArea;
    }
}
```