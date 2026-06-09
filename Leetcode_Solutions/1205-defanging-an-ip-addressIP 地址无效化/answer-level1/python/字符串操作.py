### 解题思路
字符串转列表后遍历列表元素，当元素为'.'是插入[]
后将得到的列表再使用join函数转换为字符串输出。

### 代码

```python
class Solution(object):
    def defangIPaddr(self, address):
        """
        :type address: str
        :rtype: str
        """
        self.address = address
        list_address = list(self.address)
        list_ans = []
        for i in range (0, len(list_address)):
            if(list_address[i] != '.'):
                list_ans.append(list_address[i])
            else:
                list_ans.append('[')
                list_ans.append('.')
                list_ans.append(']')
        ans = ''.join(list_ans)
        return ans      
```