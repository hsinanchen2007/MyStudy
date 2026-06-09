### 解题思路
1.所有字符串按照长度排序；
2.排序后从尾部开始将字符串每次切掉尾部元素，确认其所有子串在words中；
3.充分利用for-else循环结构，break掉的模块无法进入else语句；
注释：虽然时间复杂度很高，但是写的很辛苦，不总结下感觉对不住辛苦。

### 代码

```python3
class Solution:
    def longestWord(self, words):
        length=len(words)
        words.sort(key=len)
        res_list=[]
        for j in range(1,length):
            length_str=len(words[-j])

            for k in range(1,length_str):
                if words[-j][0:length_str-k] not in words:
                    break
            else:  
                if res_list and length_str!=len(res_list[0]):  #存在[a,cc,ab]情况时，此算法在收集‘ab’后会再次寻找剩余列表里面最大长度满足要求的字符串，如果长度改变就停止循环。
                    break
                if length_str==1 :  #若能找到的满足要求的字符串长度为1，则直接输出
                    return min(words)
                res_list.append(words[-j])      
                if len(words[-j])!=len(words[-j-1]):
                    return min(res_list)
                else:
                    continue
        return min(res_list) if res_list else ''
```