### 解题思路
为啥已经有官方题解了，我还写一个说明。
因为我觉得他们讲的太科学，小白表示很难理解。

双指针：首尾两端各一指针，然后往中间靠拢。
随着双指针的靠拢，水槽的长度变短，如果想要面积变大，那么意味着需要更高的高度。
当前状态：start h1 -- end h2
如果height[start] < height[end]，那么我们找到下一个（start++）比height[start]大的数，
    如果比height[start]小，那么在减小宽度的同时，也减少了高度，所以面积一定比原来的小。
否则 如果height[start] > height[end] 我们找到下一个（end--）比height[end]大的数。
    同理，如果比height[end]小，那么在减小宽度的同时，也减少了高度，所以面积一定比原来的小。
否则 height[start] == height[end] 我们找到下一个（start++）比height[start]大的数，找到下一个（end--）比height[end]大的数。
    如果只找一个大的数，那么存在，高度不变时，长度减小，面积减小
当双指针相遇时，就会比较所有的面积可能增加的差异数据，最后得到最大面积即为结果。

### 代码

```java
class Solution {
    public int maxArea(int[] height) {
        int start = 0;
        int end = height.length - 1;
        int res = 0;
        int h = 0;
        int base = 0;
        int tmp = 0;
        while(start < end) {
            if (height[start] > height[end])
                h = height[end];
            else
                h = height[start];
            tmp = (end - start) * h;
            if (tmp > res) {
                res = tmp;
            }
            if(height[start] < height[end]) {
                base = start++;
                while(start <= end && height[start] <= height[base]) start++;
            } else if(height[start] > height[end]) {
                base = end--;
                while(start <= end && height[end] <= height[base]) end--;
            } else {
                base = start++;
                while(start <= end && height[start] <= height[base]) start++;
                base = end--;
                while(start <= end && height[end] <= height[base]) end--;
            }
        }
        return res;
    }
}
```