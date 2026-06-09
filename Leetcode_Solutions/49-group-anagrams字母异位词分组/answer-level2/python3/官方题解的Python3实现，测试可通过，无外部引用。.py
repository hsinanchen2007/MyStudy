此类型题目模板
```python
class Solution:
    def func(self, inputs):
        res = {}
        for input in inputs:
            if key in res:
                res[key].append(input)
            else:
                res[key] = (input)
        return res

    def hashMapFunc(self, value):
        # 构建value-key关系
        return key
```


方法二可通过的Python3实现
```python
class Solution:
    def groupAnagrams(self,strs):
        temp_dict={}
        for temp_str in strs:
            sort_str = self.HashMapFunc(temp_str)
            if sort_str in temp_dict:
                temp_dict[sort_str].append(temp_str)
            else:
                temp_dict[sort_str]=[temp_str]
        return list(temp_dict.values())


    def HashMapFunc(self, temp_str):
        return ''.join(sorted(list(temp_str)))
```
执行用时 :56 ms, 在所有 Python3 提交中击败了96.16%的用户  
内存消耗 :16.2 MB, 在所有 Python3 提交中击败了61.68%的用户

方法二可通过的Python3实现
```python
class Solution:
    def groupAnagrams(self,strs):
        temp_dict={}
        for temp_str in strs:
            sort_str = self.HashMapFunc(temp_str)
            if sort_str in temp_dict:
                temp_dict[sort_str].append(temp_str)
            else:
                temp_dict[sort_str]=[temp_str]
        return list(temp_dict.values())

    def HashMapFunc(self, temp_str):
        key = [0] * 26
        for char in temp_str:
            key[ord(char) - ord('a')] += 1
        return ''.join([str(i) for i in key])
```
执行用时 :140 ms, 在所有 Python3 提交中击败了30.09%的用户  
内存消耗 :16.2 MB, 在所有 Python3 提交中击败了60.42%的用户