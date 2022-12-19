### 解题思路
此处撰写解题思路
1.字符串按空格分割到列表
2.去除空格
3.列表反转
4.列表元素拼接字符串
5.切片去除尾空格
### 代码

```python
class Solution(object):
    def reverseWords(self, s):
        ss=[]
        a=""
        ss=s.split(" ")
        for x in range(ss.count("")):
            ss.remove("")
        ss.reverse()
        for x in range(len(ss)):
            a+=(ss[x]+" ")
        return a[:-1]
```