思路一：
把数组的第一位字符串看做标准位数循环遍历(pos),从第二位字符串开始循环遍历(_),如果扫描到的字符串⻓度小于等于当前位数,则标志为False;如果扫描的字符串位置不等于标准位置,则标志为False。当出现有元素不符合公共条件，直接跳出循环。
```
class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        if not strs:
            return ''
        res = ''
        flag = True
        # 第一位字符串看做标准位数循环遍历
        for pos in range(len(strs[0])):
            # 从第二位字符串开始循环遍历
            for i in range(1, len(strs)):
                # 如果扫描到的字符串⻓度小于等于当前位数
                if pos + 1 > len(strs[i]):
                    flag = False
                # 如果扫描的字符串位置不等于标准位置
                elif strs[i][pos] != strs[0][pos]:
                    flag = False
            if flag:
                res += strs[0][pos]
            # 当出现有元素不符合公共条件，直接跳出循环
            else:
                break
        return res
         
```
思路二：
zip(*st rs)函数将列表变换成元组。然后使用集合set的互异性,判断set后的元组⻓度等于1,等于1则认为该字符是公共前缀,加入公共前缀字符串
```
class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        if not strs:
            return ''
        # 判断set后的元组⻓度等于1,等于1则认为该字符是公共前缀,加入公共前缀字符串
        res = [set(i) for i in zip(*strs) if len(set(i)) == 1]
        return strs[0][:len(res)]
```
