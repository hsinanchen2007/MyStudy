newarr1列表用来存储最终结果。
首先对arr1使用Counter,产生result,依次将arr2中出现的数字加入到newarr1，并同时已经添加至newarr1的数字从arr1中删去，
arr2中的数字全部遍历后，再将arr1中剩余的数字重新排序，追加到newarr1中。
```
class Solution(object):
    def relativeSortArray(self, arr1, arr2):
        """
        :type arr1: List[int]
        :type arr2: List[int]
        :rtype: List[int]
        """
        from collections import Counter
        newarr1 = []
        result = Counter(arr1)
        for i in range(len(arr2)):
            for j in range(result[arr2[i]]):
                newarr1.append(arr2[i])
                arr1.remove(arr2[i])
        newarr1 = newarr1 + sorted(arr1)
        return newarr1
```
![image.png](https://pic.leetcode-cn.com/4ad0ad71af81a148c9720db67c3888ac5a271aab13551383446f65c094dff83d-image.png)
