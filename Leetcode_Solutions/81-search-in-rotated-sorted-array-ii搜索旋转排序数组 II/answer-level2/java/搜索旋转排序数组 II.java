循坏、递归都可以做，递归更清晰些；
```
import java.util.*;
class Solution {
    public boolean search(int[] nums, int target) {
        return process(nums, target, 0, nums.length - 1);
    }

    public boolean process(int[] nums, int target, int left, int right) {
        if(left > right) return false;
        int mid = (left + right) / 2;
        if(target == nums[mid] || target == nums[left] || target == nums[right]) {
            return true;
        }
        if(left == right)return false;
        //mid 属于左半部分
        if (nums[mid] > nums[left]) {
            //target在left，mid之间
            if (target < nums[mid] && target > nums[left]) {
                return process(nums, target, left + 1, mid - 1);
                //target在mid之上，或者target在right之下，即要么在大于mid的左半部分，要么在右半部分
            } else if (target > nums[mid] || target < nums[right]) {
                return process(nums, target, mid + 1, right - 1);
                //其他可能都找不到
            } else return false;
            //mid属于右半部分
        } else if (nums[mid] < nums[right]) {
            if (target > nums[left] || target < nums[mid]) {
                return process(nums, target, left + 1, mid - 1);
            } else if (target > nums[mid] && target < nums[right]) {
                return process(nums, target, mid + 1, right - 1);
            } else return false;
            //不能确定mid属于左半部分还是右半部分，即nums[left] == nums[mid] == nums[right]
        } else {
            //那就对mid左边和mid右半都进行考虑
            return process(nums, target, left + 1, mid - 1) || process(nums, target, mid + 1, right - 1);
        }
    }
}
```
![截屏2020-01-19下午2.39.42.png](https://pic.leetcode-cn.com/971889d53ab3a01398af5f90009ebfc919f29121f4342340f3f0fdd5b6429051-%E6%88%AA%E5%B1%8F2020-01-19%E4%B8%8B%E5%8D%882.39.42.png)

