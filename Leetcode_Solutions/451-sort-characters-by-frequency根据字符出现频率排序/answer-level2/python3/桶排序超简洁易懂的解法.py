### 解题思路
首先创建一个字典用于存储每个元素的出现次数
然后创建一个list，根据出现的频率排序
逆序合并list输出即可

### 代码

```python
class Solution(object):
    def frequencySort(self, s):
        """
        :type s: str
        :rtype: str
        """
        # 创建一个字典用于统计每个元素的次数
        times_dict={}
        for i in s:
            times_dict[i]=times_dict.get(i,0)+1
        # 创建一个list用于存储每个元素
        buckets=['' for i in range(len(s))]
        for val,times in times_dict.items():
            buckets[times-1] += val*times
        # 逆序合并输出
        return ''.join(buckets[::-1])
```