### 1. 暴力解法
思路：首先最直观的思路就是：枚举数组中所有元素的两两组合, 然后判断这两两组合相加是否等于target, 如果等于target直接返回即可。
时间复杂度：O(n^2)
空间复杂度：O(1)
```java []
// 执行用时：24ms
public int[] twoSum(int[] nums, int target) {
    for (int i = 0; i < nums.length - 1; i++) {
        for (int j = i + 1; j < nums.length; j++) {
            if (nums[i] + nums[j] == target) {
                return new int[]{i, j};
            }
        }
    }
    return null;
}
```
```python []
# 执行用时 7412ms
def twoSum(self, nums: List[int], target: int) -> List[int]:
    for i in range(0, len(nums) - 1):
        for j in range(i + 1, len(nums)):
            if nums[i] + nums[j] == target:
                return [i, j]
```

### 2. HashMap
思路：遍历nums, 观察map中是否存在target - nums[i]的结果, 若存在返回结果, 若不存在将当前nums[i]添加到map
时间复杂度：O(n)
空间复杂度：O(n)
```java []
// 执行用时：3ms
public int[] twoSum(int[] nums, int target) {
    HashMap<Integer, Integer> map = new HashMap<>();
    for (int i = 0; i < nums.length; i++) {
        if (map.containsKey(target - nums[i])) {
            return new int[]{i, map.get(target - nums[i])};
        }
        map.put(nums[i], i);
    }
    return null;
}
```
```python []
# 52ms
def twoSum(self, nums: List[int], target: int) -> List[int]:
    dict = {}
    for i in range(len(nums)):
        if target - nums[i] in dict:
            return [dict[target - nums[i]], i]
        dict[nums[i]] = i
```
ps：这道题不知道已经是几刷了...感觉已经有10多遍了...
