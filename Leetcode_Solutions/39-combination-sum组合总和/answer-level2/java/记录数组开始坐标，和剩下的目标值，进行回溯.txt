### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public List<List<Integer>> combinationSum(int[] candidates, int target) {
       if (null == candidates || 0 == candidates.length) {
            return Collections.emptyList();
        }

        Arrays.sort(candidates);
        List<List<Integer>> cache = new ArrayList<>();
        backTrackSum(candidates, cache, target, new ArrayList<>(), 0);
        return cache;
    }

    private void backTrackSum(int[] candidates, List<List<Integer>> cache, int target, ArrayList<Integer> prefix,
        int start) {
        if (target == 0) {
            cache.add(new ArrayList<>(prefix));
            return;
        }

        if (target < 0) {
            return;
        }

        for (int i = start; i < candidates.length; ++i) {
            if (target >= candidates[i]) {
                prefix.add(candidates[i]);
                backTrackSum(candidates, cache, target - candidates[i], prefix, i);
                prefix.remove(prefix.size() - 1);
            }
        }
    }
}
```