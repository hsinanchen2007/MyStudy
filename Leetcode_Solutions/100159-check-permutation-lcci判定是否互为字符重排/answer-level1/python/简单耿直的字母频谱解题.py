### 解题思路
简单耿直的解题思路
先看了一下字符串长度是否相同，进行一步简单的排查，如果不相同的话，后边的情况根本不用考虑
当两个字符串长度相同的时候，用他们的ASCII码来制作“字母频谱”，最后比对两个“字母频谱”是否相同，来判断字符串中包含的字母的种类和个数
“字母频谱”相当于横轴为a~z的26个字母，纵轴是它们出现次数的柱状图表
本题目因为没有涉及到大小写问题，所以就简单的使用了所求字母到小写字母a的距离
如果涉及到大小写问题，则需要再把相同的大写字母和小写字母对应起来
以上为被人拙见，谢谢各位，望不吝赐教
### 代码

```python
class Solution(object):
    def CheckPermutation(self, s1, s2):
        """
        :type s1: str
        :type s2: str
        :rtype: bool
        """
        if len(s1) != len(s2):
            return False
        else:
            dic_s1=[0]*26
            dic_s2=[0]*26
            for char_in_s1 in s1:
                char_ID_in_s1 = ord(char_in_s1)-ord('a')
                dic_s1[char_ID_in_s1]+=1
            for char_in_s2 in s2:
                char_ID_in_s2 = ord(char_in_s2)-ord('a')
                dic_s2[char_ID_in_s2]+=1
            if dic_s1 == dic_s2:
                return True
            else:
                return False
```