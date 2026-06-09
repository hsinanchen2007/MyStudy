### 解题思路
归并排序思想

### 代码

```python
class Solution(object):
    def sortArray(self, array):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        
        arrayLen = len(array)
        if arrayLen < 1:
            return []
        if arrayLen ==1:
            return array
        middleNum = arrayLen // 2
        leftArray = self.sortArray(array[:middleNum])
        rightArray = self.sortArray(array[middleNum:])
        return self.MergeCore(leftArray,rightArray)
    def MergeCore(self,leftArray,rightArray):
        leftIndex = 0
        rightIndex = 0
        leftLen = len(leftArray)
        rightLen = len(rightArray)
        ret = []
        while leftIndex < leftLen and rightIndex < rightLen:
            if leftArray[leftIndex] < rightArray[rightIndex]:
                ret.append(leftArray[leftIndex])
                leftIndex += 1
            else:
                ret.append(rightArray[rightIndex])
                rightIndex += 1
        ret.extend(leftArray[leftIndex:])
        # while leftIndex < leftLen:
        #     ret.append(leftArray[leftIndex])
        #     leftIndex += 1
        ret.extend(rightArray[rightIndex:])
        # while rightIndex < rightLen:
        #     ret.append(rightArray[rightIndex])
        #     rightIndex += 1
        return ret
```