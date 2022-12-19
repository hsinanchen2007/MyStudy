### 解题思路
O(n**2)太慢了。。。

### 代码

```python
class Solution(object):
    def relativeSortArray(self, arr1, arr2):
        """
        :type arr1: List[int]
        :type arr2: List[int]
        :rtype: List[int]
        """
        out = []
        for n in arr1:
            a = False
            for j in arr2:
                if n == j:
                    a = True
            if not a:
                out.append(n)
        out.sort()
        #print(out)
        new = []
        for n in arr2:
            count = 0
            for j in arr1:
                if n == j:
                    count += 1
            if count > 0:
                for k in range(count):
                    new.append(n)
        for n in out:
            new.append(n)
        return new
        

            

```

执行用时 :
44 ms
, 在所有 python 提交中击败了
22.34%
的用户
内存消耗 :
11.9 MB
, 在所有 python 提交中击败了
100.00%
的用户