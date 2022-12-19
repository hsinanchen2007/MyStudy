解题思路：
参考3数之和得双指针移动，这里采用三指针移动。i,left,nextLeft,right四个指针，其中left = i + 1;nextLeft = left + 1; right = nums.length - 1。最内层循环就是nextLeft与right得移动，然后保证nextLeft < right 且nextLeft > left;紧跟着得循环就是left得移动，left移动是嵌套着nextLeft移动得。代码复杂度较高，用时较长，自己会研究如何优化的。
代码：
```
    public List<List<Integer>> fourSum(int[] nums, int target) {
      List<List<Integer>> res = new ArrayList<>();
        Arrays.sort(nums);
        for (int i = 0; i < nums.length - 3; i++) {
            int left = i + 1;
            while (left <= nums.length - 3) {
                int nextLeft = left + 1;
                int right = nums.length - 1;
                while (nextLeft > left && nextLeft < right) {
                    int sum = nums[i] + nums[left] + nums[nextLeft] + nums[right];
                    if (sum == target) {
                        if (!res.contains(Arrays.asList(nums[i], nums[left], nums[nextLeft], nums[right])))
                            res.add(Arrays.asList(nums[i], nums[left], nums[nextLeft], nums[right]));
                        nextLeft++;
                        right--;
                    } else if (sum < target) nextLeft++;
                    else right--;
                }
                left += 1;
            }
        }
        return res;
    }
```
