### 解题思路
此处撰写解题思路
①若字符串数组为空，直接返回空，若字符串数组只有一个元素则返回该元素。
②对字符串数组strs按字符长度进行排序，返回的数组的第一个元素为长度最小的元素。
③以第一个元素为基准字符串进行循环，然后再次循环遍历数组的每一个元素(包括第一个元素)当前index位置的字符是否与外层基准index位置的字符相同，每一次内层循环结束，则返回外层index位置的字符，直至遍历完基准字符串的所有字符。
### 代码

```python3
class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        if len(strs) == 0:
            return ""
        elif len(strs) == 1:
            return strs[0]
        new_strs = sorted(strs,key = lambda i:len(i),reverse=False)
        res = ""
        i,n = 0,len(strs)
        min_len = len(new_strs[0])
        for j in range(min_len):
            for i in range(n):
                if new_strs[i][j] == new_strs[i-1][j]:
                    if i == n-1:
                        res+=new_strs[0][j]
                        break
                    i+=1
                else:
                    return res
        return res

```