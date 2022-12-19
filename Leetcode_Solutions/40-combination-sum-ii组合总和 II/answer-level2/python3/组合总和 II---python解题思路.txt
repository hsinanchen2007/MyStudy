和之前39题同样的思路，就是回溯的参数下标变化了一下，添加到result的时候判断了一下，剩下都是一样的，具体思路参考39题

```python
class Solution:
    def combinationSum2(self, candidates: List[int], target: int) -> List[List[int]]:
        def DFS(now_index, tem_result):
            if sum(tem_result) > target: return
            if sum(tem_result) == target:
                # 排序为了去重
                tem_result.sort()
                if tem_result not in result:
                    result.append(tem_result)
                return
            for index in range(now_index, len(candidates)):
                # 不能再使用相同的元素
                DFS(index + 1, tem_result + [candidates[index]])
        
        result = []
        DFS(0, [])
        return result
```

执行结果

```
执行用时 :204 ms, 在所有 python3 提交中击败了18.48% 的用户
内存消耗 :12.7 MB, 在所有 python3 提交中击败了99.77%的用户

执行用时 :208 ms, 在所有 python3 提交中击败了18.48% 的用户
内存消耗 :12.7 MB, 在所有 python3 提交中击败了99.77%的用户

执行用时 :256 ms, 在所有 python3 提交中击败了16.98% 的用户
内存消耗 :12.7 MB, 在所有 python3 提交中击败了99.77%的用户
```

速度虽然慢，但是内存消耗竟然战胜了99% 哈哈哈

欢迎来github上看更多题目的解答[力扣解题思路](https://github.com/WRAllen/LeetCode)