**暴力解法n^3超时，采用哈希表解法与头尾指针**
## 哈希表
```
class Solution {
    public List<List<Integer>> threeSum(int[] nums) {
        if (nums.length < 3) return new LinkedList<>();
        List<List<Integer>> result = new LinkedList<>();
        Arrays.sort(nums);
        for (int i = 0; i < nums.length; ++i) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            Map<Integer, Integer> map = new HashMap<>();
            for (int j = i + 1; j < nums.length; ++j) map.put(nums[j], map.getOrDefault(nums[j], 0) + 1);
            List<Integer> list = new LinkedList<>(map.keySet());
            for (int j : list) {
                if ((-2 * j == nums[i] && map.get(j) > 1) || (-2 * j != nums[i] && (map.containsKey(-nums[i] - j)))) {
                    result.add(Arrays.asList(nums[i], j, -nums[i]-j));
                }
                map.remove(j);
            }
        }
        return result;
    }
}
```
时间复杂度: O(n^2)
空间复杂度: O(n)
## 头尾指针
**利用Set集合去重**
```
class Solution {
    public List<List<Integer>> threeSum(int[] nums) {
        if (nums.length < 3) return new LinkedList<>();
        Set<List<Integer>> result = new HashSet<>();
        Arrays.sort(nums);
        for (int i = 0; i < nums.length; ++i) {            
            int left = i + 1;
            int right = nums.length - 1;
            while (left < right) {
                if (nums[i] + nums[left] + nums[right] > 0) --right;
                else if (nums[i] + nums[left] + nums[right] < 0) ++left;
                else result.add(Arrays.asList(nums[i], nums[left++], nums[right--]));
            }
        }
        return new LinkedList(result);
    }
}
```
**自行去重**
```
class Solution {
    public List<List<Integer>> threeSum(int[] nums) {
        if (nums.length < 3) return new LinkedList<>();
        List<List<Integer>> result = new LinkedList<>();
        Arrays.sort(nums);
        for (int i = 0; i < nums.length; ++i) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            int left = i + 1;
            int right = nums.length - 1;
            while (left < right) {                
                if (nums[i] + nums[left] + nums[right] < 0) ++left;
                else if (nums[i] + nums[left] + nums[right] > 0) --right;
                else result.add(Arrays.asList(nums[i], nums[left++], nums[right--]));
                while (left > i + 1 && left < right && nums[left] == nums[left - 1]) ++left;
                while (right < nums.length - 1 && left < right && nums[right] == nums[right + 1]) --right;
            }
        }
        return result;
    }
}
```
时间复杂度: O(n^2)
空间复杂度: O(1)



