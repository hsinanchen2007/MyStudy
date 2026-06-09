### 解题思路
去重的方式比较挫，可以优化

### 代码

```java
class Solution {
    List<List<Integer>> results = new ArrayList<>();
    Set<String> set = new HashSet<>();

    public List<List<Integer>> combinationSum2(int[] candidates, int target) {
        if (candidates.length == 0) {
            return results;
        }

        List<Integer> list = new ArrayList<>();
        dfs(candidates, target, 0, list);
        return results;
    }

    private void dfs(int[] candidates, int target, int level, List<Integer> list) {
        if (target < 0) {
            return;
        }

        if (target == 0) {
            List<Integer> temp = new ArrayList<>(list);
            Collections.sort(temp);
            String string = String.valueOf(temp);
            if (!set.contains(string)) {
                set.add(string);
                results.add(new ArrayList<>(list));
            }
            return;
        }

        for (int i = level; i < candidates.length; i++) {
            if (target - candidates[i] < 0) {
                continue;
            }
            list.add(candidates[i]);
            dfs(candidates, target - candidates[i], i + 1, list);
            list.remove(list.size() - 1);
        }
    }
}
```