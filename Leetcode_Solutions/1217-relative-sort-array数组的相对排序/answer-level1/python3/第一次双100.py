![捕获.JPG](https://pic.leetcode-cn.com/5b520f0521fdbb09357fcd90ee35881456a607688c706c5f540af62e928ff54a-%E6%8D%95%E8%8E%B7.JPG)
```
class Solution(object):
    def relativeSortArray(self, arr1, arr2):
        """
        :type arr1: List[int]
        :type arr2: List[int]
        :rtype: List[int]
        """
        arr3 = []
        set_2 = set(arr2)
        for i in arr1[::-1]:
            if i not in set_2:
                arr1.remove(i)
                arr3.append(i)
        arr3.sort(reverse = True)
        for i in arr2[::-1]:
            num = arr1.count(i)
        arr3.extend([i for j in range(num)])
        return arr3[::-1]
```

