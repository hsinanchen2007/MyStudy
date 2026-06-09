### 解题思路
首先看一共有多少数，然后判断中位数出现的位置，然后逐个比较两个有序数组中最小的数，将数压入栈中，
如果个数为奇数，在压入中间那个数后结束并输出栈顶；
如果个数为偶数，压入中间两个数后结束，并输出最后两个数的均值

### 代码

```python3
class Solution:
    def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:
        tempList = []
        len1 = len(nums1)
        len2 = len(nums2)

        if (len1 + len2) % 2 == 0:
            flag = 1
        else:
            flag = 0

        tempIndex = (len1 + len2) // 2

        i = 0
        tail1 = 0
        tail2 = 0

        while i <= (tempIndex):
            if tail1 == len(nums1):
                tempList.append(nums2[tail2])
                tail2 += 1
            elif tail2 == len(nums2):
                tempList.append(nums1[tail1])
                tail1 += 1
            elif nums1[tail1] < nums2[tail2]:
                tempList.append(nums1[tail1])
                tail1 += 1
            else:
                tempList.append(nums2[tail2])
                tail2 += 1
            i = len(tempList)
        print('tail1:'+str(tail1))
        print('tail2:'+str(tail2))

        if flag == 0:
            return tempList[-1]
        else:
            return (tempList[-1] + tempList[-2]) / 2
```