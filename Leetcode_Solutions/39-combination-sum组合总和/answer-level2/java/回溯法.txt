### 解题思路
回溯法

### 代码

```java
class Solution {
    public List<List<Integer>> combinationSum(int[] candidates, int target) {
        int length = candidates.length;
        if (length == 0 || candidates == null) {
            return null;
        }
        Arrays.sort(candidates);
        List<Integer> path = new ArrayList<>();
        List<List<Integer>> ans = new ArrayList<>();
        combinationCore(candidates, target, 0, 0, length, path, ans);
        return ans;
    }

    //这个回溯不需要层级的概念，但是需要begin的概念（上一层选取的节点的横向位置），
    //因为深搜时某一层，若继续扫描begin之前的值，一定会重复
    private void combinationCore(int[] candidates, int target, 
                                int sum, int begin, int length,
                                List<Integer> path, List<List<Integer>> ans) {
        if (sum > target) {
            return;
        }
        if(sum == target) {
            ans.add(new ArrayList<>(path));
        }
        for(int i = begin; i < length; i++) {
            path.add(candidates[i]);
            combinationCore(candidates, target, sum+candidates[i], i, length, path, ans);
            path.remove(path.size()-1);
        }
                                                    
    }
}
```