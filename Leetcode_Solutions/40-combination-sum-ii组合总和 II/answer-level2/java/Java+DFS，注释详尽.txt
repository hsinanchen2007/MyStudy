1.看着别人的写的，主要补充了一些注释，添加了自己的理解。
2.113题和40题有点像，一个是树，一个是数组。可以对照练习一下。
3.DFS的模板基本有了：就是先定义一个结果容器，判空一下；然后加一个helper函数，多加几个参数，参数通常包含原来的，以及结果容器，还有路径list，以及层级（树是深度，数组是index）。
至于helper函数里面，用递归来实现，递归上来先要想好递归的终止条件是啥，然后把符合要求的放入结果容器之中，然后递归调用自己，要想好参数怎么变，以及要不要回溯。

```
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

class Solution {
    public List<List<Integer>> combinationSum2(int[] candidates, int target) {
        List<List<Integer>> result = new ArrayList<>();
        if (candidates == null || candidates.length == 0) {
            return result;
        }
        // 先排序
        Arrays.sort(candidates);
        // 辅助函数的参数的选择，应该有原来的参数，以及结果容器，中间记录的容器，以及index（对应树就是深度，对应数组就是index）
        helper(candidates, target, result, new ArrayList<>(), 0);
        return result;
    }

    private void helper(int[] candidates, int target, List<List<Integer>> result, List<Integer> list, int index) {
        // 递归的终止条件1：这里用相减的方式，target是固定值，然后取target-candidates[i]，如果等于0了，说明符合要求
        if (target == 0) {
            // 这里是为了去重，如果已经有了，就不重复添加了
            if (!result.contains(list)) {
                result.add(new ArrayList<>(list)); // 注意这里不是直接添加list，而是复制了list出来添加，因为后面list会被修改
            }
            return;
        }
        // 递归的终止条件2：对于异常的情况，直接return
        if (index >= candidates.length || target < 0 || candidates[index] > target) {
            return;
        }
        for (int i = index; i < candidates.length; i++) {
            list.add(candidates[i]);
            // ++index代表index的值先+1，然后再取最新的值。因为这里又要取最新的值，又要+1，所以这样写
            helper(candidates, target - candidates[i], result, list, ++index);
            // 如果递归之后，还不能找到合适的解，就回溯。
            list.remove(list.size() - 1);
        }
    }
}
```
