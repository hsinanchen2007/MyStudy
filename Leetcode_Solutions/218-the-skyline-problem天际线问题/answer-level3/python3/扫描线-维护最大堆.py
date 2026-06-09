本题解主要整理自 [ivan_allen](https://leetcode-cn.com/problems/the-skyline-problem/solution/218tian-ji-xian-wen-ti-sao-miao-xian-fa-by-ivan_al/) 与 [powcai](https://leetcode-cn.com/problems/the-skyline-problem/solution/fen-er-zhi-zhi-er-fen-fa-dui-by-powcai/)，并附加自己的理解


## 扫描线-BST维护：
扫描图中矩形形成的每个关键点，在关键点中维护一个BST/红黑树，矩形的左端点意味着高度入平衡二叉树，右端点则意味着需要此高度出平衡二叉树。检查每一条扫描线中的最大高度是否有变化，若有变化则是天际线中的关键点。 然而python没有平衡二叉树相关的标准库，可以参见[ivan_allen](https://leetcode-cn.com/problems/the-skyline-problem/solution/218tian-ji-xian-wen-ti-sao-miao-xian-fa-by-ivan_al/)大佬的解法


## 扫描线-最大堆维护：
在扫描线中，关注的是每条线中的最高高度，这也可以联想到最大堆。

其中的难点在于最大堆只能关注于top点，而无法直观地像BST维护那样在遇到矩形右端点时将对应矩形的高度从BST中pop掉。因此**转换一下思路，我们不必在一遇到矩形的右端点就移除该矩形的高度，而关注当前最高的矩形是否在扫描线的左侧，若最高矩形在左侧，那么就可以将此矩形清理**。

以下参考了[powcai](https://leetcode-cn.com/problems/the-skyline-problem/solution/fen-er-zhi-zhi-er-fen-fa-dui-by-powcai/)的解法和代码，大佬的代码中有很多trick，因此在此基础上添加注释与理解友好代码
```
import heapq
class Solution:
    def getSkyline(self, buildings: [[int]]) -> [[int]]:
        if len(buildings) == 0:
            return []

        points = []
        for l, r, h in buildings:
            # 左端点通过负数高度来标识，同时适用于标准库中的小顶堆转换为大顶堆
            points.append((l, -h, r))
            points.append((r, h, 0))

        # 将扫描线中的关键点按照points的前两个元素x, y来排序
        points.sort()
        # 初始值，[0初始高度， float('inf')对应无穷右边界]
        height_heap = [[0, float('inf')]]    
        res = [[0, 0]]
   
        for x, h, r in points:
            # 关键点：清除扫过的高楼
            while x >= height_heap[0][1]:
                heapq.heappop(height_heap)
            
            # 左端点入堆
            if h < 0:
                heapq.heappush(height_heap, [h, r])

            # 如果当前最大高度变化，说明是天际线中的关键点
            if res[-1][1] != -height_heap[0][0]:
                res.append([x, -height_heap[0][0]])
        
        return res[1:]
```