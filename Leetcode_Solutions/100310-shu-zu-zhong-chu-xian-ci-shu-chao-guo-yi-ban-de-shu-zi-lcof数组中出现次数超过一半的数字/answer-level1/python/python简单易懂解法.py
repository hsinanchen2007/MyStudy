一起组队刷题打卡，微博 [@爱编程的周鸟](https://weibo.com/iosxxoo) 关注交流。

### 解题思路
- 第一步：记录数组中次数出现最多的个数
- 第二步：判断这个数是否出现次数超过一半

O(n)复杂度。


### 代码

```python
class Solution(object):
    def majorityElement(self, numbers):
        res = None
        cnt = 0
        for i in numbers:  # 留下数组中出现次数最高的数
            if not res:
                res = i
                cnt = 1
            else:
                if i == res:
                    cnt += 1
                else:
                    cnt -= 1
                    if cnt == 0:
                        res = None
        # 判断次数是否大于一半
        cnt = 0 
        for i in numbers:
            if i == res:
                cnt += 1
        if cnt > len(numbers) / 2:
            return res
        else:
            return 0
```