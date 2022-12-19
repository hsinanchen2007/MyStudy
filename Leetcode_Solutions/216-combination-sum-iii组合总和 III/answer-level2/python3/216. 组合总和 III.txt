思路：
1. 回溯构造数套路基本是固定的。
2. 回溯的题的精髓就是剪枝，去除那些不需要的递归情况能明显加速程序运行。
3. 但是这道题的规模太小，回溯提升都不如官方服务器对结果的影响大。
4. 可以设一个全局变量来观察程序递归了多少次，以此来看剪枝是否有效。
# python3代码
```python
class Solution:
    def combinationSum3(self, k: int, n: int) -> List[List[int]]:
        res = []
        path = []
        def helper(cur,path,cursum):
            if(len(path) == k and cursum == n):
                res.append(path[:])
            for i in range(cur,10):
                if(i+cursum > n): #剪枝的情况
                    return
                path.append(i)
                helper(i+1,path,cursum+i)
                path.pop()
        helper(1,path,0)
        return res
```