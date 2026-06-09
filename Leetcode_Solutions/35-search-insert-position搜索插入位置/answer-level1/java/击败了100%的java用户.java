### 分析
本题和34题一样，都是二分法的变形题。
只不过我们在写二分法的时候，最后的返回值是mid，此处返回left。
为什么这么写？证明如下：
假设我们给的数组是[...,3,5,...]。现在要找的数字是4
到最后定位到left==right的时候，要么在3的位置，要么在5的位置。
假如最后定位在3的位置，nums[mid] < target,然后left = mid + 1，最后返回的left就是3后面那个位置，符合要求。
假如最后定位在5的位置，nums[mid] > target, 此时更新的是right，与left无关，最后返回的left就是5所在的位置，符合要求。
### 代码
```
public int searchInsert(int[] nums, int target) {
        if (nums == null || nums.length == 0) {
            return 0;
        }
        int left = 0, right = nums.length - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) {
                return mid;
            }
            if (nums[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return left;
    }
```
本人建了个公众号用于刷题交流，欢迎关注：
![qrcode_for_gh_8eedbc428c9a_258(1).jpg](https://pic.leetcode-cn.com/e5f794b173fbe256a541447fc7ff8e6eb031774890bdfdb48ca3c7866dc81dc2-qrcode_for_gh_8eedbc428c9a_258\(1\).jpg)