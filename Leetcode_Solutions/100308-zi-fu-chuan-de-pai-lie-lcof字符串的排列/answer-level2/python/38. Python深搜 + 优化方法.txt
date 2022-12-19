### 解题思路
对于全排列问题很常用的思路就是深搜，这道题同样可以用深搜来解决。但是考虑到字符串中可能有重复元素，很多人给出的解决方法是将结果放到一个set中去重，但是这样无疑增加了时间复杂度，所以我们的第一个优化是**记录每个位置之前已经使用过的字符**，举例，比如我们有字符串'abbc'，并且当前路径已经生成'a'，那么现在还有三个字符可以用，即'bbc'，当我们使用完'b'字符并获得了所有以'ab'为前缀的字符串时，我们又递归回来，发现第三个字符还是'b'，这时其实我们已经不需要再重新进行深搜，因为结果都是一样的，我们可以选择set来记录当前位置之前已经使用过的字符，这样也能够保证查找是O(1)时间复杂度的。
还有一个优化虽然下面代码没有实现但是也是可行的，那就是递归问题常伴随使用的**备忘录**，备忘录记录的是{可用字符:全排列}，这样同样可以显著减少时间复杂度，相当于用空间换时间。

### 代码

```python
class Solution(object):
    def permutation(self, s):
        """
        :type s: str
        :rtype: List[str]
        """
        if s == '':
            return []
        res = []
        def get_res(not_use, temp):
            print(temp)
            if not_use == '':
                res.append(temp)
                return 
            use_set = set() # 记录当前位置之前已经使用过的字符
            for i in range(len(not_use)):
                ch = not_use[i]
                if ch in use_set:
                    continue
                else:
                    get_res(not_use[:i] + not_use[i + 1:], temp + ch)
                    use_set.add(ch)

        get_res(s, '')
        return res
```