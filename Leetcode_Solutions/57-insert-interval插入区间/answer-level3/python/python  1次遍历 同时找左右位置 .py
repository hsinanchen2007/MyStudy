### 解题思路
此处撰写解题思路
python  1次遍历 同时找左右位置 
找到了 直接extend 后面 返回
始终没找到 添加位置  
最后添加 返回
### 代码

```python
class Solution(object):
    def insert(self, intervals, newInterval):
        """
        :type intervals: List[List[int]]
        :type newInterval: List[int]
        :rtype: List[List[int]]
        """
        if len(intervals) == 0:
            return [newInterval]
        res = []
        for i, node in enumerate(intervals):
            # 先看左边 左边比节点滴i个节点右边还大 跳过左边
            if node[1] < newInterval[0]:
                res.append(node)
            # 左边节点 在第i个节点 左边比新节点左边小 右边比新节点右边不大 更新新节点左边
            elif node[0] < newInterval[0] and node[1] >= newInterval [0]:
                newInterval[0] = node[0]
            # 再看右边 够不着了  结果直接添加新节点  extend 后面所有节点
            if node[0] > newInterval[1] :
                res.append(newInterval)
                res.extend(intervals[i:])
                break
            # 右节点在第i个节点内  更新新节点右侧  添加 extend 二连
            elif node[0] <= newInterval[1] and node[1] > newInterval[1]:
                newInterval[1] = node[1]
                res.append(newInterval)
                res.extend(intervals[i+1:])
                break

        # 防 所有节点 都在新节点左侧        
        if newInterval not in res:
            res.append(newInterval)

        return res
```