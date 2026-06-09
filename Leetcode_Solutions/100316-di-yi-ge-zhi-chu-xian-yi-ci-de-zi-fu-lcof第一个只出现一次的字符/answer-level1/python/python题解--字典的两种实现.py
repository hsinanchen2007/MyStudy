### 使用有序字典
![image.png](https://pic.leetcode-cn.com/547bb6fc1f2bf5ec33dfd5e8b233e26382f36cfcaaec02674e87519f3d3e4525-image.png)

- 我们建立有序字典,常规的字典是无序存储的.从开始访问`s`中的元素,依次加入有序字典中,键是对应的是每一个字符,值是这个字符出现的次数
- 遍历结束后,我们开始在字典中查找第一个值为1的键即可,否则返回`' '`
- 时间复杂度`O(n)`,空间复杂度`O(1)`,因为字符的个数是常数个

### 代码

```python
class Solution(object):
    def firstUniqChar(self, s):
        """
        :type s: str
        :rtype: str
        """
        import collections 
        dic = collections.OrderedDict()
        for i in s:
            if i in dic:
                dic[i] += 1
            else:
                dic[i] = 1
        for i,j in dic.items():
            if j == 1:
                return i
        return ' '
```

### 使用普通字典
![image.png](https://pic.leetcode-cn.com/1d2a5dbe8c0b3f4f4d705fdf75e314130671b41c88a592f518c6ef8cc48a3f28-image.png)

- 同样我们建立普通的字典,也是遍历一边字符串`s`,将这些字符和他们的出现次数放入到字典中
- 由于我们使用的是无序字典,所以字典中字符的顺序不是我们输入时的顺序
- 我们再次遍历`s`,在字典中进行查找,找到第一个值为1的字符即可,否则返回`' '`
- - 时间复杂度`O(n)`,空间复杂度`O(1)`,因为字符的个数是常数个

### 代码
```
class Solution(object):
    def firstUniqChar(self, s):
        """
        :type s: str
        :rtype: str
        """
        dic = {}
        for i in s:
            dic[i] = dic.get(i, 0) + 1
        for i in s:
            if dic[i] == 1:
                return i
        return " "


```

