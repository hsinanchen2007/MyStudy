```
class Solution:
    def combinationSum3(self, k: int, n: int):
        """
           1） 这个问题如果不需要打印具体的组合, 那么就是一个典型的背包问题。
           可以基于背包+递归的方式打印出组合
           
           2）直接使用递归，考虑一点就是1-9中的数字要么选，要么不选。前选过的元素，后面不会再选择
        """
        
        data_list = [x for x in range(1, n + 1)]
        res = []

        def backtrack(left_list, left_c, linked_list):
            # 终止条件
            if left_c == 0 and len(linked_list) == k:
                res.append(linked_list)
                return
            if left_c < 0:
                return
            if len(left_list) <= 0:
                return
            
            first_value = left_list[0]
            backtrack([y for y in range(first_value + 1, 10)], left_c, linked_list)
            backtrack([y for y in range(first_value + 1, 10)], left_c - first_value, linked_list + [first_value])


        backtrack(data_list, n, [])

        # 注意特殊情况
        return res

s = Solution()
print(s.combinationSum3(2, 18))

```
