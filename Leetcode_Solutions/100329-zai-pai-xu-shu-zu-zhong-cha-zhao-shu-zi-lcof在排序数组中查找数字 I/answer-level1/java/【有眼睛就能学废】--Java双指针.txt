### 解题思路
采用双指针方法从数组左右两端向中间开始遍历，统计值为target的元素个数。
复杂度分析：
- 时间复杂度：O(N)
- 空间复杂度：O(1)

### 代码

```java
class Solution {
    public int search(int[] nums, int target) {
        int left = 0;
        int right = nums.length - 1;
        int count = 0;
        while (left <= right) {
            if (left == right) {
                if (nums[left] == target) {
                    count++;
                }
                left++;
                right--;
                continue;
            }
            if (nums[left] == target) {
                count++;
            }
            left++;
            if (nums[right] == target) {
                count++;
            }
            right--;
        }
        return count;
    }
}
```