### 解题思路
有点暴力，167ms~
排序，三重循环，二分查找，Set去重。
时间复杂度 N*N*N*logN

### 代码

```java
class Solution {
    private boolean minFind(int[] nums, int left, int right, int target) {
        while (left <= right) {
            int mid = (left + right) / 2;
            if (nums[mid] < target) {
                left = mid + 1;
            } else if (nums[mid] > target) {
                right = mid - 1;
            } else {
                return true;
            }
        }
        return false;
    }

    public List<List<Integer>> fourSum(int[] nums, int target) {
        if (nums == null || nums.length < 4) {
            return new ArrayList<>();
        }

        Arrays.sort(nums);
        Set<List<Integer>> result = new HashSet<>();
        for (int i = 0; i < nums.length; i++) {
            for (int j = i + 1; j < nums.length; j++) {
                for (int k = nums.length - 1; k >= j + 1; k--) {
                    int three = target - nums[i] - nums[j] - nums[k];
                    if (minFind(nums, j + 1, k - 1, three)) {
                        List<Integer> tmp = new ArrayList<>();
                        tmp.add(nums[i]);
                        tmp.add(nums[j]);
                        tmp.add(three);
                        tmp.add(nums[k]);
                        result.add(tmp);
                    }
                }
            }
        }
        return new ArrayList<>(result);
    }
}
```