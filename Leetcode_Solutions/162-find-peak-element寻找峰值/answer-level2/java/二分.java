### 解题思路
此处撰写解题思路

### 代码

```java
/**
在题目描述中出现了 nums[-1] = nums[n] = -∞，这就代表着 只要数组中存在一个元素比相邻元素大，那么沿着它一定可以找到一个峰值.
根据左右指针计算中间位置 m，并比较 m 与 m+1 的值，
    如果 m 较大，则左侧存在峰值，r = m;
    如果 m + 1 较大，则右侧存在峰值，l = m + 1
*/
class Solution {
    public int findPeakElement(int[] nums) {
        int left = 0;
        int right = nums.length-1;
        while (left < right) {
            int mid = (left + right) >>> 1;
            if (nums[mid] > nums[mid+1]) {
                //下一个区间：[left, mid],mid也可能是峰值
                right = mid;  //降序
            } else {
                left = mid + 1;  // 升序
            }
        }
        return left;
    }
}
```