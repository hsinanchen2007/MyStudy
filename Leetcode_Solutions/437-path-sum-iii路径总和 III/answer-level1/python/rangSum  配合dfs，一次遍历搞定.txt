```
class Solution(object):
    def pathSum(self, root, sum):
        """
        :type root: TreeNode
        :type sum: int
        :rtype: int
        """
        return self.dfs(root, 0, sum, {})

    def dfs(self, node, pathSum, target, cache):
        if not node:
            return 0

        pathSum += node.val
        result = 0
        if pathSum == target:
            result = 1
        
        result += cache.get(pathSum - target, 0)
        cache[pathSum] = cache.get(pathSum, 0) + 1 
        result += self.dfs(node.left, pathSum, target, cache)
        result += self.dfs(node.right, pathSum, target, cache)
        cache[pathSum] -= 1
        return result
```

直觉上看，每次都重新计算和肯定有浪费，所以缓存之前的sum，因为是求个数，所以value存个数就行。