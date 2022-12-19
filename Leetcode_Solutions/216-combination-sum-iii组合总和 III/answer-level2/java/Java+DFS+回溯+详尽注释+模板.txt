39,40,216是一系列的题，做完之后可以总结模板。

![image.png](https://pic.leetcode-cn.com/3a3d944b404e5bdc7199da154c109664f7f07801ff4df3f87f2e4b66168c3a45-image.png)

```
import java.util.ArrayList;
import java.util.List;

class Solution {
    // 根据题意，定义一个全局数组变量candidates，取值只能从1-9里选
    int[] candidates = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    public List<List<Integer>> combinationSum3(int k, int n) {
        List<List<Integer>> result = new ArrayList<>();
        List<Integer> list = new ArrayList<>();
        if (n == 0) {
            return result;
        }
        helper(n, k, result, list, 0);
        return result;
    }

    // n,目标总和；k，一共有k个数；result，结果容器；list，路径容器；index，candidates的下标
    private void helper(int n, int k, List<List<Integer>> result, List<Integer> list, int index) {
        // 递归的终止条件1：如果n和k都为0，就把结果放入结果容器
        if (n == 0 && k == 0) {
            result.add(new ArrayList<>(list)); // 注意这里是先拷贝一个list出来，因为递归时list会变；因为不存在重复的数字，并且candidates我们在定义时就已经默认升序排序，所以不用做额外的排序及去重工作
            return; // 这里要返回
        }
        // 剪枝
        if (n < 0 || k < 0 || index >= candidates.length || candidates[index] > n) {
            return;
        }
        //i的起始值是index
        for (int i = index; i < candidates.length; i++) {
            list.add(candidates[i]);
            //递归。n和k的值在下一次递归时都会变，注意变化；因为“每种组合中不存在重复的数字”，所以index需要+1后传递给下一次递归，这里index先加1，后取值。
            helper(n - candidates[i], k - 1, result, list, ++index);
            // 回溯
            list.remove(list.size() - 1);
        }
    }
}
```





