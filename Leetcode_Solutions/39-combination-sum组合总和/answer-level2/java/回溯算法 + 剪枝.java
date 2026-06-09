


**思路**：根据示例 1：输入: `candidates = [2,3,6,7]`，`target = 7`。

+ 候选数组里有 `2` ，如果找到了 `7 - 2 = 5` 的所有组合，再在之前加上 `2` ，就是 `7` 的所有组合；
+ 同理考虑 `3`，如果找到了 `7 - 3 = 4` 的所有组合，再在之前加上 `3` ，就是 `7` 的所有组合，依次这样找下去；
+ 上面的思路就可以画成下面的树形图。

其实这里思路已经介绍完了，大家可以自己尝试在纸上画一下这棵树。然后编码实现，如果遇到问题，再看下面的文字。

![39-1.png](https://pic.leetcode-cn.com/fe32ae9cee9ec8e2545d038d80a8da70d809eed01c153c6f0076801baab5010d-39-1.png)

说明：

+ 蓝色结点表示：尝试找到组合之和为该数的所有组合，怎么找呢？逐个减掉候选数组中的元素即可；
+ 以 `target = 7` 为根结点，每一个分支做减法；
+ 减到 $0$ 或者负数的时候，到了叶子结点；
+ 减到 $0$ 的时候结算，这里 “结算” 的意思是添加到结果集；
+ 从根结点到叶子结点（必须为 `0`）的路径，就是题目要我们找的一个组合。


把文字的部分去掉。

![39-2.png](https://pic.leetcode-cn.com/6e40e8001540f336dacbef4baa7710f31ca00a31ad286b7aa4109a13657d8960-39-2.png)

如果这样编码的话，会发现提交不能通过，这是因**为递归树画的有问题**，下面看一下是什么原因。


![39-3.png](https://pic.leetcode-cn.com/ade93b4f0678b2b1385ad1362ff426ce0a5a800a5b0ae07dfb65f58677374559-39-3.png)

画出图以后，我看了一下，我这张图画出的结果有 $4$ 个 $0$，对应的路径是 `[[2, 2, 3], [2, 3, 2], [3, 2, 2], [7]]`，而示例中的解集只有 `[[7], [2, 2, 3]]`，很显然，重复的原因是**在较深层的结点值考虑了之前考虑过的元素，因此我们需要设置“下一轮搜索的起点”即可（这里可能没有说清楚，已经尽力了）**。

### 去重复

+ 在搜索的时候，需要设置搜索起点的下标 `begin` ，由于一个数可以使用多次，下一层的结点从这个搜索起点开始搜索；
+ 在搜索起点 `begin` 之前的数因为以前的分支搜索过了，所以一定会产生重复。


### 剪枝提速

+ 如果一个数位搜索起点都不能搜索到结果，那么比它还大的数肯定搜索不到结果，基于这个想法，我们可以对输入数组进行排序，以减少搜索的分支；

+ 排序是为了提高搜索速度，非必要；

+ 搜索问题一般复杂度较高，能剪枝就尽量需要剪枝。把候选数组排个序，遇到一个较大的数，如果以这个数为起点都搜索不到结果，后面的数就更搜索不到结果了。


#### 参考代码：

这里感谢 [@rmokerone](/u/rmokerone) 提供的 C++ 代码实现。


```Java []
import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Deque;
import java.util.List;

public class Solution {

    public List<List<Integer>> combinationSum(int[] candidates, int target) {
        List<List<Integer>> res = new ArrayList<>();
        int len = candidates.length;

        // 排序是为了提前终止搜索
        Arrays.sort(candidates);

        dfs(candidates, len, target, 0, new ArrayDeque<>(), res);
        return res;
    }

    /**
     * @param candidates 数组输入
     * @param len        输入数组的长度，冗余变量
     * @param residue    剩余数值
     * @param begin      本轮搜索的起点下标
     * @param path       从根结点到任意结点的路径
     * @param res        结果集变量
     */
    private void dfs(int[] candidates,
                     int len,
                     int residue,
                     int begin,
                     Deque<Integer> path,
                     List<List<Integer>> res) {
        if (residue == 0) {
            // 由于 path 全局只使用一份，到叶子结点的时候需要做一个拷贝
            res.add(new ArrayList<>(path));
            return;
        }

        for (int i = begin; i < len; i++) {

            // 在数组有序的前提下，剪枝
            if (residue - candidates[i] < 0) {
                break;
            }

            path.addLast(candidates[i]);
            dfs(candidates, len, residue - candidates[i], i, path, res);
            path.removeLast();

        }
    }
}
```
```Python []
from typing import List


class Solution:
    def combinationSum(self, candidates: List[int], target: int) -> List[List[int]]:
        size = len(candidates)
        if size == 0:
            return []

        # 剪枝是为了提速，在本题非必需
        candidates.sort()
        # 在遍历的过程中记录路径，它是一个栈
        path = []
        res = []
        # 注意要传入 size ，在 range 中， size 取不到
        self.__dfs(candidates, 0, size, path, res, target)
        return res

    def __dfs(self, candidates, begin, size, path, res, target):
        # 先写递归终止的情况
        if target == 0:
            # Python 中可变对象是引用传递，因此需要将当前 path 里的值拷贝出来
            # 或者使用 path.copy()
            res.append(path[:])
            return

        for index in range(begin, size):
            residue = target - candidates[index]
            # “剪枝”操作，不必递归到下一层，并且后面的分支也不必执行
            if residue < 0:
                break
            path.append(candidates[index])
            # 因为下一层不能比上一层还小，起始索引还从 index 开始
            self.__dfs(candidates, index, size, path, res, residue)
            path.pop()


if __name__ == '__main__':
    candidates = [2, 3, 6, 7]
    target = 7
    solution = Solution()
    result = solution.combinationSum(candidates, target)
    print(result)
```
```C++ []
// author:rmokerone
#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    vector<int> candidates;
    vector<vector<int>> res;
    vector<int> path;
public:
    void DFS(int start, int target) {
        if (target == 0) {
            res.push_back(path);
            return;
        }
        for (int i = start;
             i < candidates.size() && target - candidates[i] >= 0; i++) {
            path.push_back(candidates[i]);
            DFS(i, target - candidates[i]);
            path.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int> &candidates, int target) {
        std::sort(candidates.begin(), candidates.end());
        this->candidates = candidates;
        DFS(0, target);

        return res;
    }

};
```


**附注**：这道题我用的是减法，有兴趣的朋友还可以使用加法，加到 target 的时候结算，超过 target 的时候剪枝。

做完这题的朋友，不妨做一下 LeetCode 第 40 题：组合问题 II。