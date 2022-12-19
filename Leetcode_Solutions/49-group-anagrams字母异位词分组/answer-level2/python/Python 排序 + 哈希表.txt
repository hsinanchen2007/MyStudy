### 解题思路
快排 +　字典
下面的快排写成有返回值这种也是自己基本功不扎实，不知道字符串中的元素不能赋值，最后也就没改了。

### 代码

```python
class Solution(object):
    def groupAnagrams(self, strs):
        """
        :type strs: List[str]
        :rtype: List[List[str]]
        """
        def quick_sort(str):
            length = len(str)
            if length <= 1:
                return str
            p, q = 0, length - 1
            temp = str[0]
            while p < q:
                while p < q and str[q] > temp:
                    q -= 1
                if p < q:
                    str[p] = str[q]
                    p += 1
                while p < q and str[p] < temp:
                    p += 1
                if p < q:
                    str[q] = str[p]
                    q -= 1
            str[p] = temp
            return quick_sort(str[0:p]) + [str[p]] + quick_sort(str[p + 1:length])

        my_dict = {}
        for i in range(len(strs)):
            str = ''.join(quick_sort([ch for ch in strs[i]]))
            if str in my_dict:
                my_dict[str].append(strs[i])
            else:
                my_dict[str] = [strs[i]]
        return list(my_dict.values())
```