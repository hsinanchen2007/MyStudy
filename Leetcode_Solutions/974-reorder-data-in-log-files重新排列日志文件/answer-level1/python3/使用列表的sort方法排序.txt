### 解题思路
使用列表的sort排序。

先将logs中的数字日志和字母日志分别存放
题中说在想用的内容日志下，按照标识符排序，所以先将字母日志按照标识符排序，然后再根据内容首字母进行排序

### 代码

```python3
class Solution:
    def reorderLogFiles(self, logs):

        # 内容首字母排序的规则
        def takeSecond(elem):
            return elem.split(' ', 1)[1]

        List_abc =[]
        List_123 = []
        for li in logs:
            index = li.split(' ', 1)[1][:1]
            if index.isalpha():
                List_abc.append(li)
            if index.isdigit():
                List_123.append(li)
        List_abc.sort()
        List_abc.sort(key=takeSecond, reverse=False)
        return List_abc + List_123
```