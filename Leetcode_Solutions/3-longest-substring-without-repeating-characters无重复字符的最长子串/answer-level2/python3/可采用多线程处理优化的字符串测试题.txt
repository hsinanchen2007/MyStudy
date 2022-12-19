### 解题思路
初始化一个存放当前无重复元素的字符列表sub_str，和一个存放历史最长无重复元素的字符串列表sub_str_list
首先将字符串s转换为字符列表s，遍历字符列表s，如果s中的元素未曾出现在sub_str中，就加入到sub_str；如果出现过，则将首次出现这个元素的位置之后的所有元素保留下来，其他元素传入sub_str_list。最后将待处理的元素加入到sub_str。
遍历完成之后，便可以在sub_str_list中找到最长的字符串的长度，便是本题的答案

### 代码

```python3
class Solution(object):
    def lengthOfLongestSubstring(self, s):
        """
        :type s: str
        :rtype: int
        """
        s = list(s)
        sub_str = []
        sub_str_list = []
        for item in s:
            if item not in sub_str:
                sub_str.append(item)
            elif item in sub_str:
                sub_str_list.append(sub_str)
                for i in sub_str:
                    if i == item:
                        index = sub_str.index(i)
                        sub_str = sub_str[index+1:]
                        sub_str.append(item)
        sub_str_list.append(sub_str)
        print(sub_str_list)
        max = 0
        for item in sub_str_list:
            if len(item) > max:
                max = len(item)
        return max
```