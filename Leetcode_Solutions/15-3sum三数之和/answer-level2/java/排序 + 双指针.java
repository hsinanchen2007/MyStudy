### 解题思路
双指针确实巧妙，一个在开头，一个在结尾，相等就结束循环，刚好一次遍历

### 代码

```java
class Solution {
    public List<List<Integer>> threeSum(int[] nums) {
        List<List<Integer>> res = new ArrayList<>();
        if (nums.length < 3) return res;
        int k = 0, i = k + 1, j = nums.length - 1;
        Arrays.sort(nums);
        for (k = 0; k < nums.length - 2; k++) {
            if (nums[k] > 0) break;
            if (k > 0 && nums[k] == nums[k - 1]) continue;
            i = k + 1;
            j = nums.length - 1;
            while (i < j) {
                int sum = nums[k] + nums[i] + nums[j];
                if (sum > 0) j--;
                else if (sum < 0) i++;
                else {
                    List<Integer> l = new ArrayList<>();
                    l.add(nums[k]);
                    l.add(nums[i]);
                    l.add(nums[j]);
                    res.add(l);
                    while (j - 1 > i && nums[j] == nums[j - 1]) j--;
                    while (i + 1 < j && nums[i] == nums[i + 1]) i++;
                    j--;
                    i++;
                }
            }
        }
        return res;

    }
}
```