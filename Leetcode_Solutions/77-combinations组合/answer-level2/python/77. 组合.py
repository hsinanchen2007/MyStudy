### 解题思路
回溯问题只要画出树状图就能使用DFS的思想直接解决，一定直接手动画图哦！！

![image.png](https://pic.leetcode-cn.com/3ecbcb87f110db8e252c6bc29ae1bb4486647368881a44d0d9829aad5f15d507-image.png)


### 代码

```python3
class Solution:
    def combine(self, n: int, k: int) -> List[List[int]]:
        res = []

        nums = [i+1 for i in range(n)]
        res = []
        def backtrack(nums, path, res):

            if len(path) == k:
                res.append(path.copy()) # 浅拷贝， 如果直接res.append(path)只是复制了path的引用
                # 选择撤回操作将导致最后的path是[], 那么所有添加到res的都将变成[]
                return 
            
            for i in range(len(nums)):
                cur = nums[i]
                path.append(cur)
                backtrack(nums[i+1:], path, res)
                path.pop()
                # 上面三行可以变成下面一行就可以了
                # backtrack(nums[i+1:], path + [cur], res) 这样就不需要被浅拷贝困扰了
        backtrack(nums, [], res)

        return res
```