二分查找一般适用于定位某个确定的值，而不是一堆值。
所以这里的思路是用二分查找找到target，在采用顺序遍历的方式，得到所有的target

```
public int search(int[] nums, int target) {
        // 二分查找mid=(left+right)/2, left=mid+1
        int mid, left = 0;
        int right = nums.length - 1;

        int count = 0;
        while (left <= right) {
            mid = left + ((right - left) >> 1);
            if (nums[mid] == target) {
                count++;
                if (mid > 0 && nums[mid - 1] == target) {
                    for (int i = mid - 1; i >= 0; i--) {
                        if (nums[i] == target) {
                            count++;
                        } else {
                            break;
                        }
                    }
                }
                if (mid <= nums.length - 2 && nums[mid + 1] == target) {
                    for (int i = mid + 1; i <= nums.length - 1; i++) {
                        if (nums[i] == target) {
                            count++;
                        } else {
                            break;
                        }
                    }
                }
                break;
            }
            if (nums[mid] > target) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return count;
    }
```
