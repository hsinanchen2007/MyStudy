### 解题思路
while True大法好，没别的。。。

### 代码

```python
class Solution(object):
    def distributeCandies(self,candies, num_people):
        """
        :type candies: int
        :type num_people: int
        :rtype: List[int]
        """
        a = []
        for n in range(num_people):
            a.append(0)
        p=0
        while True:
            for i in range(num_people):
                if candies> (i + num_people * p + 1):
                    candies -= (i + num_people * p + 1)
                    a[i] += (i + num_people * p + 1)
                elif candies==(i + num_people * p + 1):
                    a[i] += (i + num_people * p + 1)
                    p=-1
                    break
                else:
                    a[i] += candies
                    p = -1
                    break
            #print(a)
            if p==-1:
                print(a)
                break
            p+=1
        return a
```

执行结果：
通过
显示详情
执行用时 :
20 ms
, 在所有 python 提交中击败了
91.26%
的用户
内存消耗 :
11.6 MB
, 在所有 python 提交中击败了
100.00%
的用户