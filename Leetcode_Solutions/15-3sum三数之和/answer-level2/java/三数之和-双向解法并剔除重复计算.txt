基本解法：
三层循环，然后判断结果是否是相等的
时间复杂度O(N^3)

显然太慢
优化思路：
①a+b+c=0转化为a+b=-c
②排序+从中间往两头夹的方式+减少不必要的重复计算
- 遍历排序后的数组，如果当前元素已经大于0了，就直接break
- 排序后从两边往中间夹，直到相遇结束循环
- 如果之前相等的元素已经检查过了，就直接跳过该元素，防止重复计算和结果重复。

时间复杂度 
排序O（nlog（n））
其他O（N*N）
总体时间复杂度O(n^2)
```
    public List<List<Integer>> threeSum(int[] nums) {
        if (nums == null || nums.length < 3) {
            return new ArrayList<>();
        }
        Arrays.sort(nums);
        List<List<Integer>> res = new ArrayList<>();
        for (int i = 0; i < nums.length - 2; i++) {
            int first = nums[i];
            // 大于0的情况下就不要再次计算了
            if (first > 0) {
                break;
            }
            // i-1前面的值已经算过了，相等的值的情况下就不要再次计算了
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            addTwoSum(nums, res, i + 1, nums.length - 1, -first);
        }
        return res;
    }

    private void addTwoSum(int[] nums, List<List<Integer>> res, int left, int right, int first) {
        int start = left;
        int end = right;
        while (left < right) {
            // left-1左边的值已经计算过了，不需要重复计算
            while (left > start && left < right && nums[left] == nums[left - 1]) {
                left++;
            }
            // right+1右边的值已经计算过了，不需要重复计算
            while (right < end && left < right && nums[right] == nums[right + 1]) {
                right--;
            }
            if (left >= right) break;
            int second = nums[left];
            int third = nums[right];
            int twoNum = second + third;
            if (first == twoNum) {
                List<Integer> temp = new ArrayList<>(3);
                temp.add(first);
                temp.add(second);
                temp.add(third);
                res.add(temp);
                left++;
                right--;
            } else if (first < twoNum) {
                right--;
            } else {
                left++;
            }
        }
    }
```

