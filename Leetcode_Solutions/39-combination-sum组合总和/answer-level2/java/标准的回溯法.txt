### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public List<List<Integer>> result = new ArrayList<>();

    public List<List<Integer>> combinationSum(int[] candidates, int target) {
        if (candidates.length == 0) {
            return result;
        }
        backtrace(candidates, new LinkedList<>(), 0, target, 0);
        return result;
    }

    public void backtrace(int[] candidates, LinkedList<Integer> trace, int sum, int target, int index) {
        if (sum > target) {
            return;
        }
        if (sum == target) {
            result.add(new ArrayList<>(trace));
        }

        for (int i=index; i<candidates.length; i++) {
            int cand = candidates[i];
            if (cand + sum > target) {
                continue;
            }
            trace.add(cand);
            backtrace(candidates, trace, sum+cand, target, i);
            trace.removeLast();
        }

    }
}
```