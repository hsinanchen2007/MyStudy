思路：
    双循环：外循环确定一个数，内循环利用双指针确定两个数，满足条件为三数之和为0；
    去重：外循环遇到相等的continue，例如：-1，-1，0，1，第二个-1跳过；
          内循环指针left递减和right递增之后与之前的相等continue，例如：-2，0，0，2，2
public static List<List<Integer>> threeSum(int[] nums) {
        List<List<Integer>> list = new ArrayList<List<Integer>>();
        if (nums.length < 3) return list;
        Arrays.sort(nums);
        for (int i = 0; i < nums.length; i++) {
            int left = i + 1;
            int right = nums.length - 1;
            if (i != 0 && nums[i - 1] == nums[i])
                continue;
            if (nums[i] > 0)
                break;
            while (left < right) {
                if (nums[left] + nums[right] + nums[i] == 0) {
                    List<Integer> lst = new ArrayList<>();
                    lst.add(nums[left]);
                    lst.add(nums[right]);
                    lst.add(nums[i]);
                    list.add(lst);
                    left++;
                    right--;
                    while (left < right && nums[left] == nums[left - 1] && nums[right] == nums[right + 1]) {
                        left++;
                        right--;
                    }
                } else if (nums[left] + nums[right] + nums[i] < 0) {
                    left++;
                } else {
                    right--;
                }
            }
        }
        return list;
    }   