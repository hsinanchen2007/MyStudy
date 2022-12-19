```
public List<List<Integer>> threeSum(int[] nums) {
        List<List<Integer>> lists = new ArrayList<List<Integer>>();
        Arrays.sort(nums);
        for (int i = 0; i < nums.length - 2; i++) {
            int left = i + 1;
            int right = nums.length - 1;
            do {
                while (right > left && nums[i] + nums[left] + nums[right] < 0) left++;
                while (right > left && nums[i] + nums[left] + nums[right] > 0) right--;
                if (right > left && nums[i] + nums[left] + nums[right] == 0) {
                    // left right 去重
                    while (right > left + 1 && nums[left + 1] == nums[left]) left++;
                    while (right > left + 1 && nums[right - 1] == nums[right]) right--;
                    lists.add(Arrays.asList(nums[i], nums[left], nums[right]));
                    left++;
                    right--;
                }
            } while (left < right);
            // 首位去重
            while (i < nums.length - 1 && nums[i] == nums[i + 1] && i + 1 < left) i++;
        }
        return lists;
    }
```
（1）原始数组排序
（2）固定首位i,两边收缩找到匹配值
（3）找到之后分别移动left和right进行去重
（4）继续寻找i匹配的三元组，直到left和right两个指针碰到
（5）首位去重
![屏幕快照 2020-04-02 下午4.33.44.png](https://pic.leetcode-cn.com/538615d0e8e4fe475b19a62216c2d5d7ecdbf398378507b291c3b05d060d0e33-%E5%B1%8F%E5%B9%95%E5%BF%AB%E7%85%A7%202020-04-02%20%E4%B8%8B%E5%8D%884.33.44.png)
