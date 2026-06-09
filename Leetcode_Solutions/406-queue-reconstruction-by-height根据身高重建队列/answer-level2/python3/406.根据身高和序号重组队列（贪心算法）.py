### 解题思路
因为低身高的插入对高身高类间顺序无任何影响，所以
1.先按照身高降序，序号升序排列。
2.把同一身高的，按照序号插入对应队列序号中即可
![image.png](https://pic.leetcode-cn.com/f29bc8e24584fa239576933b62b20b61ad3748f91a02a590283c263f1d7ccf62-image.png)


### 代码

```python
class Solution(object):
    def reconstructQueue(self, people):
        """
        :type people: List[List[int]]
        :rtype: List[List[int]]
        """
        people.sort(key=lambda x:(-x[0],x[1]))
        output = [] 
        for p in people:
            output.insert(p[1],p)
        return output

```