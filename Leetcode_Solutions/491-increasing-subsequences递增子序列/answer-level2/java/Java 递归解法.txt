### 解题思路
全局维护一个Set来去重，每次递归的时候，判断当前是否可以组成递归序列，可以的话就加入到list中，在下一次递归中会加入到set中

### 代码

```java
class Solution {
    Set<List<Integer>> res;
    int[] nums;
    int n;
    public List<List<Integer>> findSubsequences(int[] nums) {
        this.nums = nums;
        this.n = n;
        res = new HashSet<>();
        helper(new ArrayList<Integer>(), 0);
        return new ArrayList(res);
    }

    void helper(List<Integer> cur, int start) {
        if (cur.size() >= 2) {
            res.add(new ArrayList<Integer>(cur));
        }
        for (int i = start; i < nums.length; i ++) {
            if (cur.size() == 0 || cur.get(cur.size() - 1) <= nums[i]) {
                cur.add(nums[i]);
                helper(cur, i + 1);
                cur.remove(cur.size() - 1);
            }
        }
    }
}
```