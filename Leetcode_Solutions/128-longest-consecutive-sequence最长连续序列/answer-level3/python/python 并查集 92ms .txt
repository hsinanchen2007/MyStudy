```
from typing import List
class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        if not nums: return 0
        father = [i for i in range(len(nums))]
        mapDict = {}        # 用来存储节点值与索引值的映射关系
        resDict = {}        # 用来存放经过并查以后的结果

        def findFather(node):
            tmp = node
            while father[node] != node:     # node 最终会指向根节点
                node = father[node]
            while tmp != father[tmp]:       # 路径压缩，同一根节点下的所有子节点均指向根节点
                curValue = tmp
                tmp = father[tmp]
                father[curValue] = node
            return node

        def union(nodeA, nodeB):
            fa, fb = findFather(nodeA), findFather(nodeB)
            # 大的元素作为父节点
            father[fa] = fb

        for index, item in enumerate(nums):
            if item not in mapDict:
                mapDict[item] = index

        for curIndex in range(len(nums)):
            curNum = nums[curIndex]
            if curNum not in resDict:       # 如果当前节点不在resDict中，则判断该节点左右节点
                preNum, nextNum = curNum - 1, curNum + 1
                if preNum in mapDict:       # 如果左节点存在，则合并当前节点与左节点
                    preIndex = mapDict.get(preNum)
                    union(curIndex, preIndex)
                if nextNum in mapDict:      # 如果右节点存在，则合并当前节点与右节点
                    nextIndex = mapDict.get(nextNum)
                    union(curIndex, nextIndex)
                resDict[curNum] = curIndex
        res = [0] * len(nums)
        for index in range(len(nums)):      # 统计相同根节点的个数
            res[findFather(index)] += 1
        return max(res)

if __name__ == '__main__':
    a = Solution()
    nums = [0, 1, -1]
    print(a.longestConsecutive(nums))
```
