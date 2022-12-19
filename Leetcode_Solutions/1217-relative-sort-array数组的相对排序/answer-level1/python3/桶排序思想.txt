第一次写题解，注释都已经写清楚放入代码块
```
class Solution:
    def relativeSortArray(self, arr1: List[int], arr2: List[int]) -> List[int]:
        maxvalue = max(arr1)
        counts = [0] * (maxvalue+1) #利用最大值创建桶
        for i in range(len(arr1)):
            counts[arr1[i]] += 1    #遍历arr1将arr1的值放入对应的桶中，每个桶代表相同值个数
        res = []    #临时数组存放结果
        for i in range(len(arr2)):
            res += counts[arr2[i]]*[arr2[i]] #遍历arr2，按照arr2的顺序放入res,[arr2[i]]代表值，counts[arr2[i]]代表有几个值
            counts[arr2[i]] = 0 #将已添加的值清0
        for k in range(len(counts)):
            if counts[k] != 0:  #遍历桶数组，将没有在arr2中出现的值加入res
                res += counts[k] * [k]  #第一次遍历的时候一排好序，只要将数值以及数值的个数依次加入res
        return res
```
![1.png](https://pic.leetcode-cn.com/aff40e2178e1f8a6dd55caca9ef77fb87a7744f0d564ab1bda0ae163766ba685-1.png)

