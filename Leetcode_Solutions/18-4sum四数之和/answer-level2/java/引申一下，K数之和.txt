``` java
class Solution {
        public List<List<Integer>> fourSum(int[] nums, int target) {
            Arrays.sort(nums);
            return kSum(nums, 4, 0, target);
        }

        private List<List<Integer>> kSum(int[] nums, int k, int start, int target) {
            List<List<Integer>> res = new LinkedList<>();
            if (k == 2) {
                int l = start, r = nums.length - 1;
                while (l < r) {
                    List<Integer> path = new LinkedList<>();
                    if (target - nums[l] == nums[r]) {
                        path.add(nums[l]);
                        path.add(nums[r]);
                        res.add(path);
                        while (l < r && nums[l] == nums[l + 1]) l++;
                        while (l < r && nums[r] == nums[r - 1]) r--;
                        l++;
                        r--;
                    } else if (nums[l] + nums[r] < target) {
                        l++;
                    } else {
                        r--;
                    }
                }
                return res;
            } else {
                for (int i = start; i < nums.length - (k - 1); i++) {

                    if (i > start && nums[i] == nums[i - 1]) continue;

                    List<List<Integer>> tmp = kSum(nums, k - 1, i + 1, target - nums[i]);

                    for (List<Integer> t : tmp) {
                        t.add(0, nums[i]);
                    }
                    res.addAll(tmp);
                }
                return res;
            }
        }
    }
```
