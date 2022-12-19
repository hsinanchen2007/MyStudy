### 解题思路
* 与39的区别在于本题不能重复选取数字，所以即回溯时下一层的起始节点位置要+1
* 但同时数组中也会出现重复的数字，所以进行去重的处理

### 代码

```java
class Solution {
    // 与39的区别在于本题不能重复选取数字，所以即回溯时下一层的起始节点位置要+1
    // 但同时数组中也会出现重复的数字
    public List<List<Integer>> combinationSum2(int[] candidates, int target) {
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
            if(i > begin && candidates[i-1] == candidates[i]) {   //修改（添加）部分1
                continue;
            }
            path.add(candidates[i]);
            combinationCore(candidates, target, sum+candidates[i], i+1, length, path, ans);     //修改部分2
            path.remove(path.size()-1);
        }
                                                    
    }
}
```