### 解题思路
1.把字母进行排序
2.字母排序后形成的是一个列表，如果要做成字典，需要将列表转化为字符串，str()函数。
3.字典中为键赋值，dic[key].append()，生成字典用dict.setdeafault('key',[]),此时如果字典中已经有该键不重复设置，如果没有该健，添加新键。
4dic.keys()对应所有的键，dic.values()对应所有的键值，获取键值利用dic['key']， key需要为字符串。
### 代码

```python3
class Solution(object):
    def groupAnagrams(self, strs):
        ans = []
        dic = {}
        for i in strs:
            a = sorted(i)#对每一个字符串进行排序
            b = str(a)#排序的结果是一个列表，需要变成字符串
            dic.setdefault(b,[])
            dic[b].append(i)#为字典的每个健赋值
        for key in dic.keys():
            ans.append(dic[key])#字典查询对应健的值为dic[key]
        return ans


```