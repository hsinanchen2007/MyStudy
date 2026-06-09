### 解题思路
时间复杂度必须是 O(log n) 级别。当然是二分查找
![image.png](https://pic.leetcode-cn.com/ab72cc5e57c78b6a8cd2cc59fc488b2c107db95d968555ea82c62a097203fe23-image.png)

### 代码

```java
class Solution {    //二叉
    public int[] searchRange(int[] nums, int target) {
        int left = 0;
        int right = nums.length - 1;
        int begin = -1;
        int end = -1;
        int[] res = new int[2];
        while(left <= right){
            int mid = (left + right)/2;
            if(nums[mid] == target){
                int temp1 = mid;
                int temp2 = mid;
                while(temp1 >= 0 && nums[temp1] == target)
                    temp1--;
                while(temp2 < nums.length && nums[temp2] == target)
                    temp2 ++;
                begin = temp1 + 1;
                end = temp2 - 1;
                break;
            }
            else if(nums[mid] < target)
                left = mid + 1;
            else
                right = mid - 1;
        }
        res[0] = begin;
        res[1] = end;
        return res;
    }
}
```