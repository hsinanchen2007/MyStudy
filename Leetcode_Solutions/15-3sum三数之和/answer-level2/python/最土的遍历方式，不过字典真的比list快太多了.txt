### 解题思路
最土的遍历代码，可以再优化，不过字典 hash是真快呀

执行用时 :
480 ms, 在所有 Python3 提交中击败了98.01%的用户
内存消耗 :
20.6 MB, 在所有 Python3 提交中击败了5.13%的用户

### 代码

```python3
class Solution(object):
    def threeSum(self, nums: list) -> list:

        resultList = []
        zeroList = []
        negativeDict = {}
        negativeDoubleDict = {}
        positiveDict = {}
        positiveDoubleDict = {}

        for item in nums:
            if item < 0:
                if -item in negativeDict:
                    negativeDoubleDict[-item] = 1
                else:
                    negativeDict[-item] = -item
            elif item == 0:
                zeroList.append(item)
            else:
                if item in positiveDict:
                    positiveDoubleDict[item] = 1
                else:
                    positiveDict[item] = item

        if len(zeroList) >= 3:
            resultList.append((0, 0, 0))
        # [+][0][-]
        if len(zeroList) > 0:
            for item in list(negativeDict.keys()):
                if item in positiveDict:
                    resultList.append((0, item, -item))

        if len(negativeDict.keys()) == 0 or len(positiveDict.keys()) == 0:
            return resultList
        # [+][+][-]

        for item1 in list(positiveDict.keys()):
            for item2 in list(positiveDict.keys()):
                if item2 != item1:
                    if (item1 + item2) in negativeDict:
                        tmp = sorted([item1, item2, -(item1 + item2)])
                        resultList.append(tuple(tmp))
                else:
                    if item2 in positiveDoubleDict:
                        if (item1 + item2) in negativeDict:
                            tmp = sorted([item1, item2, -(item1 + item2)])
                            resultList.append(tuple(tmp))
                            positiveDoubleDict.pop(item2)
        # [-][-][+]
        for item1 in list(negativeDict.keys()):
            for item2 in list(negativeDict.keys()):
                if item2 != item1:
                    if (item1 + item2) in positiveDict:
                        tmp = sorted([-item1, -item2, (item1 + item2)])
                        resultList.append(tuple(tmp))
                else:
                    if item2 in negativeDoubleDict:
                        if (item1 + item2) in positiveDict:
                            tmp = sorted([-item1, -item2, (item1 + item2)])
                            resultList.append(tuple(tmp))
                            negativeDoubleDict.pop(item2)
        # 用字典去重
        dictTemp = {}
        for item in resultList:
            dictTemp[item] = 0

        resultList2 = []
        for item in dictTemp.keys():
            resultList2.append(list(item))
        return resultList2

```