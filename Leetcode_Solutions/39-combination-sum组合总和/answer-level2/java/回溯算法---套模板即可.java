## 思路

直接上回溯算法框架。解决一个回溯问题，实际上就是一个决策树的遍历过程。你只需要思考 3 个问题：

**1、路径：也就是已经做出的选择。**

**2、选择列表：也就是你当前可以做的选择。**

**3、结束条件：也就是到达决策树底层，无法再做选择的条件。**

代码方面，回溯算法的框架：

```python
result = []
def backtrack(路径, 选择列表):
    if 满足结束条件:
        result.add(路径)
        return

for 选择 in 选择列表:
    做选择
    backtrack(路径, 选择列表)
    撤销选择
```

其核心就是 for 循环里面的递归，在递归调用之前「做选择」，在递归调用之后「撤销选择」，特别简单。

> labuladong 回溯框架！！！老哥写的文章真是干净利落！

## demo(全排列)

```java
List<List<Integer>> res = new LinkedList<>();

/* 主函数，输入一组不重复的数字，返回它们的全排列 */
List<List<Integer>> permute(int[] nums) {
    // 记录「路径」
    // 这里的 选择列表 即包含在nums中
    LinkedList<Integer> track = new LinkedList<>();
    backtrack(nums, track);
    return res;
}

// 路径：记录在 track 中
// 选择列表：nums 中的元素
// 结束条件：nums 中的元素全都在 track 中出现
void backtrack(int[] nums, LinkedList<Integer> track) {
    // 触发结束条件
    if (track.size() == nums.length) {
        res.add(new LinkedList(track));
        return;
    }
    
    for (int i = 0; i < nums.length; i++) {
        // 排除不合法的选择
        if (track.contains(nums[i]))
            continue;
        // 做选择
        track.add(nums[i]);
        // 进入下一层决策树
        backtrack(nums, track);
        // 取消选择，返回上一层决策树
        track.removeLast();
    }
}
```

## 代码实现

先按照demo写一个差不多的，这个暂时无法做到去重！

```java
public class combinationSum_39 {

    public static void main(String[] args) {
        combinationSum(new int[]{2,3,6,7},7);
        System.out.println(res);

    }
    public static List<List<Integer>> res =  new LinkedList<>();

    public static List<List<Integer>> combinationSum(int[] candidates, int target) {
        LinkedList<Integer> track = new LinkedList<>();
        // 排序的原因是在回溯的时候比较容易剪枝
        Arrays.sort(candidates);
       	// 套用上面的公式，candidates是指选择列表，target用来判断是否结束以及用于剪枝
        // track则是路径，即已经做出的选择
        backtrack(candidates, target, track);
        return res;
    }

    private static void backtrack(int[] candidates, int target, LinkedList<Integer> track) {
        //先判断结束条件
        if (target < 0) return;
        if (target == 0){
            // 当target等于0的时候，将路径加入到结果列表中
            res.add(new LinkedList<>(track));
            return;
        }
        // 遍历选择列表，这里没有去重
        //下面会设置start，每次递归的时候只在candidates中当前及之后的数字中选择。
        for(int i = 0;i < candidates.length;i++){
            // 这就是排序的好处，可以直接这样剪枝，否则还得遍历
            if(target < candidates[i]) break;
            track.add(candidates[i]);
            backtrack(candidates,target-candidates[i],track);
            track.removeLast();
        }
    }
}
```

```java
输出：[[2, 2, 3], [2, 3, 2], [3, 2, 2], [7]]
```

去重之后的代码：

```java
public class combinationSum_39 {

    public static void main(String[] args) {
        combinationSum(new int[]{2,3,6,7},7);
        System.out.println(res);

    }
    public static List<List<Integer>> res =  new LinkedList<>();

    public static List<List<Integer>> combinationSum(int[] candidates, int target) {
        LinkedList<Integer> track = new LinkedList<>();
        Arrays.sort(candidates);
        backtrack(candidates, 0, target, track);
        return res;
    }

    private static void backtrack(int[] candidates, int start, int target, LinkedList<Integer> track) {
        if (target < 0) return;
        if (target == 0){
            res.add(new LinkedList<>(track));
            return;
        }
        for(int i = start;i < candidates.length;i++){
            if(target < candidates[i]) break;
            track.add(candidates[i]);
            backtrack(candidates,i,target-candidates[i],track);
            track.removeLast();
        }
    }
}
```

```java
输出：[[2, 2, 3], [7]]
```

