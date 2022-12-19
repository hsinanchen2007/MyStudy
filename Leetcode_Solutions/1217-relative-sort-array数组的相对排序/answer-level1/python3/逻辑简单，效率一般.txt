### 解题思路
1、先计算arr1中，每一个数字出现的次数 s
2、遍历arr2
3、结合s，获得每个值的次数，向结果result中append
4、temp保存在arr1中，但不在arr2中的值，并使用sorted排序
5、将result和temp 一起返回

### 代码

```python3
class Solution:
    def relativeSortArray(self, arr1: List[int], arr2: List[int]) -> List[int]:
        s = collections.Counter(arr1)
        result = []
        for a2 in arr2:
            temp = s[a2]
            result += [a2 for _ in range(temp)]
        temp = []
        for a1 in arr1:
            if a1 not in arr2:
                temp.append(a1)
        temp = sorted(temp)
        return result + temp


```