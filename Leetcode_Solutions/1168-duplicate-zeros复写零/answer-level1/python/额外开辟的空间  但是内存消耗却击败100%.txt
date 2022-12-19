![1566762351(1).jpg](https://pic.leetcode-cn.com/500ffa85bb63e746e2a379f316726d471ccc870aeea7d8a40339665141610994-1566762351\(1\).jpg)


class Solution(object):
    def duplicateZeros(self, arr):
        """
        :type arr: List[int]
        :rtype: None Do not return anything, modify arr in-place instead.
        """
        newArr = []
        for n in range(len(arr)):
            if arr[n]:
                newArr.append(arr[n])
            else:
                newArr.append(0)
                newArr.append(0)
       # print newArr
        for i in range(len(arr)):
            arr[i] = newArr[i]
            #if arr[i] != newArr[i]:
             #   arr[i] = newArr[i]
        
