### 解题思路
每个元素只能使用一次  那么在回溯的过程中需要记录上一次添加的元素的index 再回溯的过程中+1
先排序再回溯 就会存在4种情况需要处理:
    1. 剩余的数小于0  说明这条路径是错误的  直接return;
    2. 剩余的数为0    说明正好这条路径是其中一个答案  添加到ans中并结束循环;
    3. 剩余的数大于0且小于数组第一个数  说明这一步减去的数不够 continue 迭代到减大于当前数的值
    4. 已经遍历出当前位置为candidates[i]的答案 为了避免出现重复答案 需要将i移到相同数字的后一位

### 代码

```java
class Solution {
    List<List<Integer>> ans = new ArrayList<>();
    public List<List<Integer>> combinationSum2(int[] candidates, int target) {
        // 每个元素只能使用一次 那就index+1
        Arrays.sort(candidates);
        backtrack(candidates, target, 0, new ArrayList<Integer>());
        return ans;
    }
    public void backtrack(int[] candidates, int target, int index, List<Integer> tmp) {
        for (int i = index; i < candidates.length && target >= candidates[i]; i++) {
            int leftover = target - candidates[i];
            if (leftover < 0 ) return;
            List<Integer> list = new ArrayList<>(tmp);
            list.add(candidates[i]);
            if (leftover == 0) {ans.add(list); return; }
            if (leftover < candidates[0]) {continue; }
            backtrack(candidates, leftover, i + 1, list);
            // 去掉答案中位置相同元素相同的情况
            while (i < candidates.length - 1 && candidates[i+1] == candidates[i]) i++;
        }
    }
}
```