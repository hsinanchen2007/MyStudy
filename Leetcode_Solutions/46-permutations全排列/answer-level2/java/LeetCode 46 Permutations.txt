# 解法思路（一）
- 排列的问题；
- 回溯法；
- 当给出输入的数组，代表整个排列组合的树就已经形成了，如下： 

&emsp;&emsp;&emsp;&emsp;![算法过程.png](https://pic.leetcode-cn.com/bf1d2e9875f6662ceac49e961bf28271af63487b1a4c47b04f6254d13347dac5-file_1562777693556)

- 问题转换成了，求这棵树中，所有从根节点到空节点的路径；
###### 排列和组合的区别
- 排列的递归树是这样的：当选中一个元素后，下一个元素只要不是这个元素就行；
- 组合的递归树是这样的：当选中一个元素后，下一个元素只能是选中元素之后的元素；

# 解法实现（一）
###### 关键字
`回溯` `递归` `树` `树的路径` `排列`
###### 实现细节
- 由于树上每一层的边是有冲突的，上层的边用过的数字，下层的边就不能再用了，所以在回溯的过程中，要将边的状态置为可用；
- 已经确定的排列组合在往 `res` 中放的时候，要注意是深拷贝，否则递归过程中找到的组合保存不下来；
- 用一个辅助数组 `used` 记录每个数字是否可选的状态；
```
package leetcode._46;

import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;

public class Solution46_1 {

    private List<List<Integer>> res;
    private boolean[] used;

    public List<List<Integer>> permute(int[] nums) {

        res = new ArrayList<List<Integer>>();
        if (nums == null || nums.length == 0) {
            return res;
        }

        used = new boolean[nums.length];
        LinkedList<Integer> combination = new LinkedList<>();

        findCombination(nums, 0, combination);

        return res;
    }

    private void findCombination(int[] nums, int index, LinkedList<Integer> combination) {

        if (index == nums.length) {
            res.add((List<Integer>)combination.clone());
            return;
        }

        for (int i = 0; i < nums.length; i++) {
            if (!used[i]) {
                combination.addLast(nums[i]);
                used[i] = true;
                findCombination(nums, index + 1, combination);
                combination.removeLast();
                used[i] = false;
            }
        }

        return;
    }

}
```
[返回 LeetCode [Java] 目录](https://www.jianshu.com/p/2cc66577f7d7)