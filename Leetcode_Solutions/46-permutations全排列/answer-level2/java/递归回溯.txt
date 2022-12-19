### 解题思路
同之前的递归回溯逻辑基本一致

### 代码

```java
class Solution {
    private boolean[] used;
    private int[] nums;

    public List<List<Integer>> permute(int[] nums) {
        this.nums = nums;
        this.used = new boolean[nums.length];
        List<List<Integer>> result = new ArrayList<>();
        List<Integer> record = new ArrayList<>();
        backTrack(0, record, result);
        return result;
    }

    public void backTrack(int iter, List<Integer> record, List<List<Integer>> result) {
        if (iter == nums.length) {
            result.add(new ArrayList<>(record));
            return;
        }
        for (int i = 0; i < nums.length; i++) {
            if (!used[i]) {
                record.add(nums[i]);
                used[i] = true;
                backTrack(iter + 1, record, result);
                record.remove(record.size() - 1);
                used[i] = false;
            }
        }
    }
}
```