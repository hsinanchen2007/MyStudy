看了题解，终于把思路看懂了。

图源知乎：

![图片1.png](https://pic.leetcode-cn.com/ba9f392bbbf8485ee98cd2c3ada91d10045083637f22c81406ae4f42df3e0090-%E5%9B%BE%E7%89%871.png)


每个节点维护两个数组，第一个数组(代码中的nums)包含可选节点，第二个数组包含已选节点(代码中的temp)
nums[:i]+nums[i+1:] 代表选择i节点的数字，nums只但去掉nums[i], tmp加上已选择的节点nums[i]
每次nums可选节点为空的时候代表节点选择完毕，路径构建完全。将路径加入返回数组res中。
```
class Solution:
    def permute(self, nums: List[int]) -> List[List[int]]:

        res = []

        # nums是当前节点可供选择的点，tmp是路径
        def backtrack(nums, tmp):
            if not nums:
                res.append(tmp)
                return 

            for i in range(len(nums)):
                # nums[:i]+nums[i+1:] 代表选择i节点的数字，nums只但去掉nums[i],tmp加上已选择的节点nums[i]
                backtrack(nums[:i] + nums[i+1:], tmp + [nums[i]])

        backtrack(nums, [])
        return res
```
