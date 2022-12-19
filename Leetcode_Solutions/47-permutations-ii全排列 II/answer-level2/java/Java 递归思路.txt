### 解题思路
相比无重复数字的全排列

多了Arrays.sort(nums);
和if (visit[i] || i > 0 && nums[i] == nums[i - 1] && !visit[i - 1]) continue;
### 代码

```java
class Solution {
    List<List<Integer>> res = new ArrayList<>();
    int[] nums;
    int n;
    boolean[] visit;
    public List<List<Integer>> permuteUnique(int[] nums) {
        Arrays.sort(nums);
        this.nums = nums;
        this.n = nums.length;
        visit = new boolean[n];
        helper(new ArrayList<Integer>());
        return res;
    }

    void helper(List<Integer> cur) {
        if (cur.size() == n) {
            res.add(new ArrayList<>(cur));
        }
        for (int i = 0; i < n; i ++) {
            if (visit[i] || i > 0 && nums[i] == nums[i - 1] && !visit[i - 1]) continue;
            cur.add(nums[i]);
            visit[i] = true;
            helper(cur);
            visit[i] = false;
            cur.remove(cur.size() - 1);
        }
    }
}
```