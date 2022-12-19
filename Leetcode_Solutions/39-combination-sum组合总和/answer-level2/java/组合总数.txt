### 解题思路
回溯算法(深度优先遍历)+剪枝
1. 深度优先遍历，直到找到满足和等于target时停止。
2. 不同于普通深度优先遍历的是，需要记录path，每个元素可重复使用，结果中不能有重复的组合。
3. 使用一个Deque来记录path，在找到满足条件的路径时将path添加到res中，所以需要把path和res都作为参数传入递归函数中。
4. 记录下次递归的开始位置（防止数组中的元素被重复遍历），将下次的开始位置设为本次遍历的开始位置就可以使得元素可以无限重复利用；
5. 一个优化的思路是进行剪枝，剪枝的前提是要对数组进行排序。

### 代码

```java
class Solution {
    public List<List<Integer>> combinationSum(int[] candidates, int target) {
        List<List<Integer>> res = new ArrayList<>();
        int len = candidates.length;
        Arrays.sort(candidates);
        def(candidates,len,target,0,new ArrayDeque<>(),res);
        return res;
    }
    public void def(int[] candidates, int len, int residue, int begin, Deque<Integer> path, List<List<Integer>> res) {
        if (residue == 0) {
            res.add(new ArrayList<>(path));
            return;
        }
        //因为数组中没有重复元素，所以不会有重复组合，又因为考虑的是组合而不是排列，所以只需要从i到最后中间的所有元素。
        //如果是求排列的话，就要数组中的所有元素，而不是从i到最后。
        for (int i = begin; i < len; i++) {
            if (residue - candidates[i] < 0) {
                break;
            }
            path.addLast(candidates[i]);
            //从当前位置开始，而不是从下一个位置开始，保证了一个元素可以用多次
            def(candidates,len,residue-candidates[i],i,path,res);
            path.removeLast();
        }
    }
}
```