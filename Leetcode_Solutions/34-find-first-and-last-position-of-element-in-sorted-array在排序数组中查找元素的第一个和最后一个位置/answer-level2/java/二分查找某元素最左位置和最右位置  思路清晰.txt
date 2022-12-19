
注意边界的判断，防止溢出。
相对于普通二分查找，
查询最左位置，当索引等于目标值且非最左，需要从右往左收缩区间，再二分循环。
查询最右位置，当索引等于目标值且非最右，需要从左往右收缩区间，再二分。

```
  public int[] searchRange(int[] nums, int target) {
        int[] res = new int[]{-1, -1};
        res[0] = searchRangeLeft(nums, target);
        res[1] = searchRangeRight(nums, target);
        return res;
    }

    public int searchRangeLeft(int[] nums, int target) {
        int left = 0, right = nums.length - 1, mid;
        while (left <= right) {
            mid = (left + right) >>> 1;
            if (nums[mid] == target) {
                if (mid == 0 || nums[mid - 1] != target) {
                    return mid;
                } else {
                    right = mid - 1;
                }
            } else if (nums[mid] > target) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return -1;
    }

    public int searchRangeRight(int[] nums, int target) {
        int left = 0, right = nums.length - 1, mid;
        while (left <= right) {
            mid = (left + right) >>> 1;
            if (nums[mid] == target) {
                if (mid == nums.length - 1 || nums[mid + 1] != target) {
                    return mid;
                } else {
                    left = mid + 1;
                }
            } else if (nums[mid] > target) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return -1;
    }

    @Test
    public void test() {
        System.out.println(Arrays.toString(searchRange(new int[]{5, 7, 7, 8, 8, 10}, 8)));
        System.out.println(Arrays.toString(searchRange(new int[]{5, 7, 7, 8, 8, 10}, 6)));
        System.out.println(Arrays.toString(searchRange(new int[]{1}, 1)));
        System.out.println(Arrays.toString(searchRange(new int[]{3, 3, 3}, 3)));
    }
```
