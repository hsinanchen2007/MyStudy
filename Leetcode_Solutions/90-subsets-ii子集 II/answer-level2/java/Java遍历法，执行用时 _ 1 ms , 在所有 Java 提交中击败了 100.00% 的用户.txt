### 代码

```java
class Solution {
    public List<List<Integer>> subsetsWithDup(int[] nums) {
        Arrays.sort(nums);
        List<List<Integer>> ans = new ArrayList<>();
        ans.add(new ArrayList<Integer>());
        int lastSize = 1;
        for (int i = 0; i < nums.length; i ++) {
            int ansSize = ans.size();
            for (int j = 0; j < ansSize; j ++) {
                List<Integer> sub = new ArrayList<>(ans.get(j));
                // 如果第i个数与前一个数相同，则跳过上次遍历过的部分
                if (i > 0 && nums[i] == nums[i - 1] && j < lastSize)
                    continue;
                sub.add(nums[i]);
                ans.add(sub);
            }
            lastSize = ansSize;
        }
        return ans;
    }
}
```