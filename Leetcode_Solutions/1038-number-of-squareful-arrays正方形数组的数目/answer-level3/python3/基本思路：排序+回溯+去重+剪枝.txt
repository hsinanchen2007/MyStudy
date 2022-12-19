### 解题思路
原谅我用蠢办法（捂脸），这道题我的解法是在带有重复数字的全排列问题（可参考[LeetCode47](https://leetcode-cn.com/problems/permutations-ii/)）基础上增加一个判断正方形数组操作。
理论上来讲时间复杂度是o(N!)，对于python3肯定是没法通过的，我增加了一项剪枝操作，极大幅度地缩短了执行用时。思路是在DFS遍历中，如果当前倒数第一和倒数第二个元素已经无法构成正方形数组了，那么也就没有继续搜索的必要了。

### 代码

```python3
from typing import List
import math
class Solution:
    def numSquarefulPerms(self, A: List[int]) -> int:

        len_list = len(A)
        if len_list == 0:
            return 0
        if len_list == 1:
            if math.sqrt(A[0]) % 1 == 0:
                return 1
            else:
                return 0
        self.res = 0
        A.sort()
        used = [False for _ in A]

        # def _judge(A: List[int]) -> int:
        #     '''
        #     先设计一个判断函数，用来判断是否是正方形排列数组
        #     :param A: 待判定数组
        #     :return: 0或1 其中0代表不是正方形排列 1代表是正方形排列
        #     '''
        #     for i in range(len(A)-1):
        #         if math.sqrt(A[i]+A[i+1]) % 1 != 0:
        #             return 0
        #     return 1

        def _new_judge(a: int, b: int) -> bool:
            '''
            先设计一个判断函数，用来判断相邻的两个数是否构成正方形排列
            :param a:
            :param b:
            :return:
            '''
            if math.sqrt(a+b) % 1 != 0:
                return False
            return True

        def _track_back(depth: int, path: List[int], used: List[bool]):
            '''
            回溯函数，用来求得无重复的排列数组，同时调用_judge函数计算res值
            :param depth: 当前树深度
            :param path: 当前遍历元素
            :param used: 元素使用情况
            :return:
            '''
            # 这里用到了剪枝
            if depth > 1 and not _new_judge(path[-1], path[-2]):
                return
            if depth == len_list:
                self.res += 1
                return
            for i in range(len_list):
                if not used[i]:
                    if i>0 and A[i]==A[i-1] and not used[i-1]:
                        continue
                    used[i] = True
                    path.append(A[i])
                    _track_back(depth+1, path, used)
                    # 回复原状
                    used[i] = False
                    path.pop()

        _track_back(0, [], used)
        return self.res

```