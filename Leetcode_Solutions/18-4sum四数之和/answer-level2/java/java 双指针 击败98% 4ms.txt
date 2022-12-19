与15题解相似，先进行排序
- 固定第一个元素i(使用后，跳过重复元素i)
- 遍历[i+1...length-2]区间范围的第二个元素j(使用后，跳过重复j)
- 使用双指针[head...tail]找出符合元素(找出后，跳过重复元素)
```java
class Solution {
   // 每次固定i 遍历 j = [i+1...length-2] 双指针 [head...tail] = [j+1...length-1]
    public List<List<Integer>> fourSum(int[] nums, int target) {
        List<List<Integer>> res = new ArrayList<>();
        Arrays.sort(nums);
        for (int i = 0; i < nums.length - 3; i++) {
            // 从i开始 最小值 > target 后面没戏
            if (nums[i] + nums[i + 1] + nums[i + 2] + nums[i + 3] > target) {
                break;
            }
            // 从i开始 最大值 < target 当前i没戏
            if (nums[i] + nums[nums.length - 1] + nums[nums.length - 2] + nums[nums.length - 3] < target) {
                continue;
            }
            // 遍历j
            for (int j = i + 1; j < nums.length - 2; j++) {
                int sum = nums[i] + nums[j];
                int head = j + 1;
                int tail = nums.length - 1;
                while (head < tail) {
                    // 当前和
                    int count = nums[head] + nums[tail] + sum;
                    if (count == target) {
                        res.add(Arrays.asList(nums[i], nums[j], nums[head], nums[tail]));
                        // 跳过相同head
                        while (head < tail && nums[head] == nums[head + 1]) {
                            head++;
                        }
                        // 跳过相同tail
                        while (head < tail && nums[tail] == nums[tail - 1]) {
                            tail--;
                        }
                    }
                    if (count > target) {
                        tail--;
                    } else {
                        head++;
                    }
                }
                // 跳过重复j
                while (j<nums.length-2 && nums[j] == nums[j + 1]) {
                    j++;
                }
            }
            //跳过重复i
            while(i<nums.length - 3 && nums[i] == nums[i + 1]){
                i++;
            }
        }
        return res;
    }
}
```
