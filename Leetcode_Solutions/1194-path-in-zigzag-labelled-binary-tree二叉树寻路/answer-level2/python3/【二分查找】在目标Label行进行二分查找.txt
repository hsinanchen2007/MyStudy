### 解题思路

思想：二分查找

在目标label行进行二分查找，假设每一行都是从小到大顺序排列的，如果目标label小于mid，则从个节点开始遍历到左节点，将根节点和根左节点push到结果数组，反之右节点；再次进行二分即遍及到第三层节点，以此类推，知道遍历节点等于目标label则停止，退出循环。

本题中节点是“Z”型排列，只需要在决定获取左子节点还有右子节点的时候和获取子节点函数中进行适配处理即可。

结果用时：28ms

### 代码

```python3
class Solution:
    def pathInZigZagTree(self, label: int) -> List[int]:
        '''
        
        '''
        layer = 1
        result = []
        while True:
            if 2**(layer-1) <= label < 2**layer:
                break
            else:
                layer += 1
        
        isCurLayerReversed = self.isReversed(layer)
        curLabel = 1
        curLayer = 1
        high = 2**layer-1
        low = 2**(layer-1)
        while True:
            result.append(curLabel)
            if curLabel == label:
                break
            
            mid = (high + low) / 2
            isGetLeft = (not isCurLayerReversed and label < mid) or \
                        (isCurLayerReversed and label > mid)
            curLabel = self.getChildLabel(curLabel, isGetLeft, curLayer)
            curLayer += 1

            if label < mid:
                high = int(mid)
            else:
                low = int(mid)+1
        return result

                
    def isReversed(self, layer):
        '''
        :layer 层数，从1开始
        :return Bool
        '''
        if layer % 2 == 0:
            return True
        else:
            return False
    
    def getChildLabel(self, label, left, curLayer):
        '''
        :left 是否获取左子节点
        :curLayer 当前层数，从1开始
        :return label
        '''
        high = 2**curLayer-1
        low = 2**(curLayer-1)
        label = low + high - label
        isCurLayerReversed = self.isReversed(curLayer)
        if left and isCurLayerReversed:
            return label * 2
        elif left and not isCurLayerReversed:
            return label * 2 + 1
        elif not left and isCurLayerReversed:
            return label * 2 + 1
        elif not left and not isCurLayerReversed:
            return label * 2

```