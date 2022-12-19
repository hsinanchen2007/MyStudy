### 解题思路
哈希表

### 代码

```python
class Solution(object):
    def singleNumber(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """

        hash_tabel = set()
        for num in nums:
            if num not in hash_tabel:
                hash_tabel.add(num)
            else:
                hash_tabel.remove(num)
        return hash_tabel.pop()

```


### 解题思路
列表list

### 代码

```python
class Solution(object):
    def singleNumber(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """

        dictnum = []
        for num in nums:
            if num not in dictnum:
                dictnum.append(num)
                # print dictnum
            else:
                dictnum.remove(num)
        return dictnum.pop()
```