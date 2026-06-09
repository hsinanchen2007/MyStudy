### 代码

```java
class Solution {
    public List<List<Integer>> combinationSum2(int[] candidates, int target) {
        Set<List<Integer>> result = new HashSet<>();
        if (candidates == null || candidates.length == 0) {
            return new ArrayList<>();
        }

        Arrays.sort(candidates);
        combinationSumCore(candidates, target, 0, 0, result, new ArrayList<Integer>());

        return new ArrayList<>(result);
    }

    private void combinationSumCore(int[] candidates, int target, int current, int index, Set<List<Integer>> result, List<Integer> list) {
        if (target == current) {
            result.add(list);
            return;
        }

        while (index < candidates.length && current + candidates[index] <= target) {
            List<Integer> temp = new ArrayList<>(list);
            temp.add(candidates[index]);
            combinationSumCore(candidates, target, current + candidates[index], ++ index, result, temp);
        }
    }
}
```