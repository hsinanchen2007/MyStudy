字典的key是字符串sorted后的输出，value是列表，装字母异位词
ps:和大佬的哈希有差距
```
class Solution(object):
    def groupAnagrams(self, strs):
        """
        :type strs: List[str]
        :rtype: List[List[str]]
        """
        if not strs:
            return strs

        zidian = {}
        res = []
        for i in strs:
            tmp = "".join(sorted(i))
            if tmp not in zidian:
                zidian[tmp] = [i]
            else:
                zidian[tmp]  = zidian[tmp] + [i]

        for j in zidian:
            res.append(zidian[j])

        return res
```
