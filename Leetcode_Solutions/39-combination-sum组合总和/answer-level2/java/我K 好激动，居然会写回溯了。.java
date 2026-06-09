### 解题思路
回溯关键点：考虑清楚要传的参数有哪些？考虑清楚递归结束条件。考虑清楚如何保存结果。

### 代码

```java
class Solution {
  List<List<Integer>> results = new ArrayList<>();

    public List<List<Integer>> combinationSum(int[] candidates, int target) {
        if (candidates.length == 0) {
            return results;
        }

        Arrays.sort(candidates);
        List<Integer> list = new ArrayList<>();
        dfs(candidates, target, 0, list);
        return results;
    }

    private void dfs(int[] candidates, int target, int start, List<Integer> list) {
        if (target < 0) {
            return;
        }
        if (target == 0) {
            results.add(new ArrayList<>(list));
            return;
        }

        for (int i = start; i < candidates.length; i++) {
            int value = candidates[i];
            list.add(value);
            dfs(candidates, target - value, i, list);
            list.remove(list.size() - 1);
        }
    }
}
```