解法很简单，前半部分是为了排除strs为空与集合中有""的情况与对集合进行排序，让集合中的元素以长度由小到大排列。完成了准备工作，下一步我们仅需比较最短的元素与其他集合中的元素的公共前缀集合。
一个字母一个字母进行比较，若相同则count+1,当一个字母比较完后，若count等于strs的长度，则表明这个字母是所有元素的前缀，我们就开始比较下一个字母，直到count不等于strs的长度，我们return先前比较过的所有字母即可。
```
class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        strs.sort(key = lambda i:len(i),reverse=False)
        res = ""
        if len(strs) == 0:
            return res
        fri_num = strs[0]
        if fri_num == "":
            return res
        count = 0
        
        for i in range(len(fri_num)):
            for j in strs:
                if fri_num[i] == j[i]:
                        count += 1
            if count == len(strs):
                res += fri_num[i]
                count = 0
            else:
                break
        return res
```
