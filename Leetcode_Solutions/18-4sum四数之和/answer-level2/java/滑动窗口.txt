```
class Solution {
    public List<List<Integer>> fourSum(int[] nums, int target) {
        List<List<Integer>> ansList = new ArrayList<>();
        if (nums == null || nums.length < 4) {
            return ansList;
        }
        int len = nums.length;
        Arrays.sort(nums);
        //i为起点，j为终点，left与right构成滑动窗口
        for (int i = 0; i < len - 3; i++) {
            //排序后最小sum值
            if (nums[i] * 4 > target) {
                break;
            }
            //跳过起点值相同元素，避免重复解
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            for (int j = len - 1; j - i > 2; j--) {
                //排序后最大sum值
                if (nums[j] * 4 < target) {
                    break;
                }
                //跳过终点值相同元素，避免重复解
                if (j < len - 1 && nums[j] == nums[j + 1]) {
                    continue;
                }
                int left = i + 1, right = j - 1;
                while (left < right) {
                    int sum = nums[i] + nums[left] + nums[right] + nums[j];
                    if (sum == target) {
                        ansList.add(Arrays.asList(nums[i], nums[left], nums[right], nums[j]));
                        //跳过相同元素，避免重复解
                        while (left < len - 2 && nums[left + 1] == nums[left]) {
                            left++;
                        }
                        //跳过相同元素，避免重复解
                        while (right > 2 && nums[right - 1] == nums[right]) {
                            right--;
                        }
                        left++;
                        right--;
                    } else if (sum > target) {
                        //跳过right值相同元素，避免重复计算相同sum
                        while (right > 2 && nums[right - 1] == nums[right]) {
                            right--;
                        }
                        right--;
                    } else {
                        //跳过left值相同元素，避免重复计算相同sum
                        while (left < len - 2 && nums[left + 1] == nums[left]) {
                            left++;
                        }
                        left++;
                    }

                }
            }
        }
        return ansList;
    }
}
```
