# 思路
- 三数和 = nums[i] + 两数和
- 由于可能出现重复数字的情况,因此要先将数组进行排序便于去重
- 遍历整个数组,对于每个nums[i],在nums[i:nums.length]这段区间中找到两数和
- 这里三数和为0,因此要找到两数和 = -nums[i](nums[i] + 两数和 = 0)
- 最后注意去重操作
# 例子
- 对于用例 [-1, 0, 1, 2, -1, -4]
- 首先排序 [-4, -1, -1, 0, 1, 2]
- 遍历,第一个元素为-4,需要在[-1, -1, 0, 1, 2]中找到和为4的两个数,然而并没有
- 对于第二个元素-1,需要在[-1, 0, 1, 2]找到和为1的两个数,找到[-1,2],[0,1]
- 第三个元素也是-1,因此跳过
- 第四个元素是0,由于本题是找三数和为0的数字,而数组又是有序的,因此已经可以停止寻找(但我在代码中没有这样做)
# 代码
```
public List<List<Integer>> threeSum(int[] nums) {
        List<List<Integer>> resultSet = new ArrayList<>();
        Arrays.sort(nums);
        int i = 0;
        while (i < nums.length - 2) {
            int target = -nums[i];
            //找两数和
            int j = i + 1;
            Set<Integer> map = new HashSet<>();
            while (j < nums.length) {
                if (map.contains(nums[j])) {
                    //找到两数和后加入结果集,并跳到下一个不同的数开始寻找(去重)
                    resultSet.add(new ArrayList<>(Arrays.asList(nums[i], nums[j], target - nums[j])));
                    int dup = nums[j];
                    while (j < nums.length && nums[j] == dup) j++;
                } else {
                    map.add(target - nums[j]);
                    j++;
                }
            }
            //去重操作,找到下一个不同的数
            while (i < nums.length - 2 && nums[i] == -target) i++;
        }
        return resultSet;
    }
```
