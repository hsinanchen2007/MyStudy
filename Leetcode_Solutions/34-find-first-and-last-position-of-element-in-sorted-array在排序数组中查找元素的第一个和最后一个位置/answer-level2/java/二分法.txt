### 解题思路
一看到log（n）的时间复杂度就大致是二分法了，这道题思路也是比较简单，找到符合条件的左右下标即可；
如果数组中存在target，那么：
1、左面的边界下标left一定要满足nums[left] > nums[left - 1];
2、右面的边界下标right一定要满足nums[right] < nums[right + 1]
两次遍历，一次找左下标，一次找右下标（特别注意处理left==0和right==nums.length - 1的情况）

### 代码

```java
class Solution {
    public int[] searchRange(int[] nums, int target) {
        int l = 0,r = nums.length - 1;
        int[] res = new int[2];
        res[0] = -1;
        res[1] = -1;
        if(r == -1)
            return res;
        int mid = 0;
        while(l <= r){
            mid = (l + r) / 2;
            if(nums[mid] > target)
                r = mid - 1;
            else if(nums[mid] < target)
                l = mid + 1;
            else
                if(mid >= 1)
                    if(nums[mid] > nums[mid - 1]){
                        res[0] = mid;
                        break;
                    }
                    else
                        r = mid - 1;
                else{
                    res[0] = mid;
                    break;
                }
        }
        l = 0;
        r = nums.length - 1;
        while(l <= r){
            mid = (l + r) / 2;
            if(nums[mid] > target)
                r = mid - 1;
            else if(nums[mid] < target)
                l = mid + 1;
            else
                if(mid < nums.length - 1)
                    if(nums[mid] < nums[mid + 1]){
                        res[1] = mid;
                        break;
                    }
                    else
                        l = mid + 1;
                else{
                    res[1] = mid;
                    break;
                }
        }
        return res;
    }
}
```