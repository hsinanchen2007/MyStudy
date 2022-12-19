### 解题思路
此处撰写解题思路
![TIM截图20200209175239.png](https://pic.leetcode-cn.com/ef02ecdfa426d3468f46140dfa9301de9c6a09f798963849c83646b93f5e9a70-TIM%E6%88%AA%E5%9B%BE20200209175239.png)

从数学的角度去分析，把数分成两个部分，第一个部分为做除法的部分，第二部分为做减法的部分。
做除法的次数(N)应该是使2的N次方刚好等于或小于这个数。 pre = int(math.log(num, 2))
第二部分应该为 last = num-pre, 然后转换成2进制(b_last)。再计算b_last中bit位为1的个数
两部分之和再加一就是处理需要的步数
![B58A2B8C8F00DD5E113FA03613234D62.png](https://pic.leetcode-cn.com/f323306f4f069d73cd7924a53719d143876e391f976ec0296b71b2c3abc2c527-B58A2B8C8F00DD5E113FA03613234D62.png)


### 代码

```python
class Solution(object):
    def numberOfSteps (self, num):
        """
        :type num: int
        :rtype: int
        """
        pre = int(math.log(num, 2))
        last = num - 2**pre
        b_last = bin(last)
        b_last = b_last[2:]
        result1 = 0
        for i in b_last:
            result1 += int(i)
        result = result1 + pre + 1
        return result
        
```