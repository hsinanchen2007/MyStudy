### 解题思路
此处撰写解题思路

### 代码

```java
/**
整体思路：用二分查找算法，在数组中查找一个数，这个数的值 >= 这个数（包括）到数组最后一个数的长度（len-mid），最后返回:len-left
要返回选取的区间的长度，而选取的区间要满足区间中的数大于等于所在区间的长度。
    // 思路：因为数组升序排列，所以比较 nums[mid]的值 和区间 [mid, len - 1] 的长度（即 len - 1 - mid + 1 = len - mid）
    // 要返回的是 nums 中的值
    // [0, 1, 2, 5, 6]，

*/
class Solution {
    public int hIndex(int[] citations) {
        // 特判
        if(citations == null || citations.length == 0 || citations[citations.length-1] == 0) {
            return 0;
        }
        int left = 0;
        int right = citations.length - 1;
        int len = citations.length;
        
        while (left < right) {
            int mid = (left + right) >>> 1;
            // mid处值比长度小，就得去掉该值
            if (citations[mid] < (len-mid)) {
                left = mid + 1;
            } else {
                // 比长度大是满足的，我们应该继续让 mid 往左走去尝试看有没有更小的 mid 值
                // 可以满足 mid 对应的值 >= 从 [mid, len - 1] 的长度
                right = mid;
            }
        }
        return len-left;
    }
}
```