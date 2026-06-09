### 解题思路
引用一下评论里 xuelimin 的解题思路，说得很清楚了:
“做完829题过来的，譬如说如果有两个连续的数之和等于target，那么相差为1， (target - 1) % 2 == 0， 且数组一定是从 (target - 1) / 2开始的，数组的元素就是2个；如果是3个连续的数组，那么三个数之间相差为1、2，(target - 1 - 2) % 3 == 0，且数组一定是从 (target - 1 - 2) / 3开始的，数组元素是3个，依次类推，但是注意target必须是大于0的数，且res需要倒序”

代码写得很丑陋，尽管是运气，不过好歹也是第一次双百，所以就纪念一下啦

### 代码

```python3
class Solution:
    def findContinuousSequence(self, target):
        res = []
        count = 1
        num = 1
        start = 0
        
        #count是指需要每次需要递减的最后一个值，为了方便直接用的求和公式：（首项+count）*项数/2
        while target > ((1 + count) * count // 2):
            num = (1 + count) * count // 2
            flag = (target - num) % (count + 1)
            if not flag:
                start = (target - num) // (count + 1)
            else:
                count += 1 
                continue
            if start:
                i = count
                j = 0
                tmp = []
                while i + 1:
                    tmp.append(start + j)
                    i -= 1
                    j += 1
                res.insert(0,tmp)
            count += 1
        return res
        

                


```

![QQ截图20200306135312.png](https://pic.leetcode-cn.com/ef61cecf74bdbbdaa4748614b200b559959359a52b4cd678baf154784f2634d0-QQ%E6%88%AA%E5%9B%BE20200306135312.png)
