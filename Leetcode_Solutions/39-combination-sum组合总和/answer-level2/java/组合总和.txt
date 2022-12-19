### 解题思路
基本思路：dfs遍历所有种可能性，将符合条件的加入结果中
剪纸条件：当当前和大于目标时候，这时直接返回，
加入结果条件：当当前和==目标时候，需要添加到结果中去，但是需要进行去重一下，
备注：本代码先对数组进行排序，达到去重结果

### 代码

```java
class Solution {
    public List<List<Integer>> combinationSum(int[] candidates, int target) {
        List<List<Integer>> result = new ArrayList<>();
        Arrays.sort(candidates);
        getResult(candidates, 0, target, result, 0, new ArrayList<>());
        return result;
    }
    public void getResult(int[] candidates, int start, int target, List<List<Integer>> result, int curSum, List<Integer> oneResult) {
        if (curSum > target) {
            return;
        }
        if (curSum == target) {
            result.add(new ArrayList<>(oneResult));
            return;
        }
        for (int i = start; i < candidates.length; i++) {
            oneResult.add(candidates[i]);
            getResult(candidates, i, target, result, curSum+candidates[i], oneResult);
            oneResult.remove(oneResult.size()-1);
        }
    }
}
```