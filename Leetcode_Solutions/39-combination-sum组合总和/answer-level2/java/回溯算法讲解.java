### 解题思路
现在一看到排列这两个字 就不由自主的想到 回溯算法， 不过回溯算法也有很多变种，基本上回溯算法的有固定的范式


``` java
if(condition){
    list.add(res);
}
for(i in nums){
    res.add(i)
    backtrack()
    res.removeLast()
}
```

但是本题想说的不是这个范式 ，这个范式大家都知道 属于最基础的回溯范式。
解决 排列 、组合类 问题关键点在于 for 循环里面条件设置，如果要求是组合 一般要求不能重复设置的，我们 for循环 i 一般要在 backtrack 中进行传递，如何要求排列，那么我们就需要记录访问过的节点，然后每次对访问的状态进行添加移除操作。此时我们一般需要引入一个临时 visited[]来标记状态 

### 代码

```java
class Solution {
    List<List<Integer>> combinationSum;
    private HashSet<Set<Integer>> resSet = new HashSet<>();

    public List<List<Integer>> combinationSum(int[] candidates, int target) {
        // Arrays.sort(candidates);
        combinationSum = new ArrayList<>();
        // 伪代码
        // 1 保存下探遍历数组 满足 res == target return list
        // 2 添加list
        // 3 return list
        LinkedList linkedList = new LinkedList<Integer>();
        backTrack(linkedList, candidates, target, 0, 0);
        return combinationSum;
    }

    public void backTrack(LinkedList<Integer> res, int[] candidates, int target, int sum, int start) {
        if (sum == target) {
            // if (resSet.contains(new HashSet(res))) {
            //     return;
            // }
            // resSet.add(new HashSet(res));
            combinationSum.add(new ArrayList<>(res));
            return;
        }
        if (sum > target) {
            return;
        }
        for (int i = start; i < candidates.length; i++) {
            int num = candidates[i];
            res.offerLast(num);
            backTrack(res, candidates, target, sum + num, i);
            res.pollLast();
        }
    }
}
```