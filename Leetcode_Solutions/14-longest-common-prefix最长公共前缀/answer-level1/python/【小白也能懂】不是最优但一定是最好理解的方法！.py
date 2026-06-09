```
class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        if not strs:
            return ""

        # 如果只有一个element，公共前缀就是他本身
        if len(strs) == 1:
            return strs[0]

        res = ""
        for i in range(len(strs[0])):
            # 我们每次取strs里第一个element的前i个字符，来和后面的string里的elements对比
            common = strs[0][:i+1]
            # 首先假设所有字符串到到i位都是相同的
            allSame = True
            # 遍历后面每一个string
            for j in range(1,len(strs)):
                # 一旦出现不相等的 我们就不用找后面的了
                if(strs[j][:i+1] != common):
                    allSame = False
                    break
            # 只有确定后面所有的string到i位的字符都是相等的 我们才更新
            if allSame == True:
                res = common
        return res
```
