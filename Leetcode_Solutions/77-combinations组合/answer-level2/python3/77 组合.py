# [77. 组合](https://leetcode-cn.com/problems/combinations/comments/)
思路：
1. 还是采用回溯生成树，不过这个和全排列不同的地方在于，全排列的循环是从头开始循环，生成树的情况更多。
2. 由于组合要求的是每一个元素不能重复，所以元素的只需要向后回溯即可。树的深度也就是元素k的个数。
3. 加上一行剪枝的情况，可以将速度提升2倍多。
4. 测试比官方程序的答案还快，说明这个剪枝还是挺成功的。
```python
class Solution:
    def combine(self, n: int, k: int) -> List[List[int]]:
        import copy
        res = []
        path = []

        def helper(path,cur):
            if(len(path) == k):
                res.append(copy.deepcopy(path))

            if(len(path)+n-cur+1 >= k): #剪枝情况，不加也可以，就是运行的更慢

                for i in range(cur,n+1):
                    if(i not in path):
                        path.append(i)
                        helper(path,i+1)
                        path.pop()

        helper(path,1)
        return res
```