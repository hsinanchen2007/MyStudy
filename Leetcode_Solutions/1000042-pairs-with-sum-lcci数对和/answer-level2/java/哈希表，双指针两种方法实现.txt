第一种实现方法：利用哈希表辅助实现。
思路：把出现过的元素当成key，元素出现的次数当成value存到map中，如果遍历到某一个元素num，查看target - num元素是否出现过，如果出现过，那么可以组成一个整数对，注意这里一个数只能属于一个数对，所以判断target - num元素出现的次数，如果为1，直接remove即可，否则更新target - num元素出现的次数-1。
```
class Solution {
    public List<List<Integer>> pairSums(int[] nums, int target) {
        //key:数组的元素;value:该元素出现的次数
        Map<Integer, Integer> map = new HashMap<>();
        
        List<List<Integer>> ans = new ArrayList<>();
        for (int num : nums) {
            Integer count = map.get(target - num);
            if (count != null) {
                ans.add(Arrays.asList(num, target - num));
                if (count == 1)
                    map.remove(target - num);
                else
                    map.put(target - num, --count);
            } else 
                map.put(num, map.getOrDefault(num, 0) + 1);
        }
        
        return ans;
    }
}
```
第二种实现方法：使用双指针实现，注意要先对数组进行排序处理。
```
class Solution {
    public List<List<Integer>> pairSums(int[] nums, int target) {
        //对数组进行排序
        Arrays.sort(nums);
        
        List<List<Integer>> ans = new LinkedList<>();
        int left = 0, right = nums.length - 1;
        while (left < right) {
            //两个指针所指的两个元素和
            int sum = nums[left] + nums[right];
            //如果两个的和小于目标值，那么left指针向右走一步继续寻找
            if (sum < target)
                ++left;
            //如果两个的和大于目标值，那么right指针向左走一步继续寻找
            else if (sum > target)
                --right;
            //如果刚好等于要找的target值，那么加入结果集中，并且left指针和right指针分别向右和向左走一步(因为一个数只能属于一个数对)
            else 
                ans.add(Arrays.asList(nums[left++], nums[right--]));
            
        }
        
        return ans;
    }
}
```


