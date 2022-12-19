### 解题思路
这里只需要维护两个变量num和flag,flag%num_people控制发到哪个孩子，num控制发放数量，如果现有糖果不足以发放的话，我们只需要在当前孩子上发放现在所有的糖果就可以。注意每个孩子都应该是+=。

### 代码

```python
class Solution(object):
    def distributeCandies(self, candies, num_people):
        """
        :type candies: int
        :type num_people: int
        :rtype: List[int]
        """
        ans=[0]*num_people
        num=1
        flag=0
        while True:
            if candies<=num:
                ans[flag%num_people]+=candies
                break
            else:
                candies-=num
                ans[flag%num_people]+=num
                num+=1
                flag+=1
        return ans
```