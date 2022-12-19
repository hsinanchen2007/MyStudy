题目设置了每个元素都是单个数字，因此可以用拆开成10位的讨巧做法，但如果不限制大小，那么只能按余数处理，其他高赞解也写得很清楚了，详细算法可以看下其他解，大致思路如下：
首先确定一点，在满足条件的情况下，答案长度越长，数字越大，即1000大于999，在长度相同的情况下，比较大小，因此先尽量地增加答案长度
将输入的数字分为三类，余0、余1和余2，余0的全部都放进答案，因为一定整除
将余1的和余2的排序后放入前面3n个（比如余2的数字总共7个，就放进去最大的6个，剩1个，若总共6个，放进去3个，剩3个，除非总共0个，否则最终剩1、2或者3个，至于为什么要剩3个，举例2 2 1 1 1）
然后剩下的余1和余2的（0-6个数）有多种组合方式，就是中间if那一段，把所有的情况都加入备选方案，然后按长度排序，如果长度相同，按大小排序（均是降序），然后取第一个加入答案
最终将答案所有数字降序排序然后连起来即可
可能程序还有问题，望指正
因为涉及排序和转换，速度不算快
![1.png](https://pic.leetcode-cn.com/b992aa57250e1e658e5954f8c687f207310204cc0dc5e12c774bf522b7501835-1.png)


```python
class Solution(object):
    def largestMultipleOfThree(self, digits):
        remain0, remain1, remain2 = [], [], []

        for i in digits:
            temp = i % 3
            if 0 == temp:
                remain0.append(i)
            elif 1 == temp:
                remain1.append(i)
            else:
                remain2.append(i)

        remain1, remain2 = sorted(remain1, reverse=True), sorted(remain2, reverse=True)
        len1, len2 = len(remain1), len(remain2)
        max1, max2 = 3 * int(len1 / 3), 3 * int(len2 / 3)
        if max1 == len1:
            max1 -= 3
        if max2 == len2:
            max2 -= 3
        remain0 += remain1[:max1] + remain2[:max2]
        remain1, remain2 = remain1[max1:], remain2[max2:]
        # print(max1, max2)

        len1, len2 = len(remain1), len(remain2)
        pending = []
        if (len1 == 0 or len1 == 3) and (len2 == 0 or len2 == 3):
            pending.append(remain1 + remain2)
        if len1 == 3:
            pending.append(remain1)
        if len2 == 3:
            pending.append(remain2)
        if len(remain1) >= 2 and len(remain2) >= 2:
            pending.append(remain1[:2] + remain2[:2])
        if len(remain1) >= 1 and len(remain2) >= 1:
            pending.append(remain1[:1] + remain2[:1])
        pending = sorted(pending, key=lambda x: self.comp(x))
        # print(pending)
        if pending:
            remain0 += pending[0]

        if not remain0:
            return ""
        remain0 = sorted(remain0, reverse=True)
        ans, flag = "", 1
        for i in remain0:
            if flag:
                if i:
                    flag = 0
                else:
                    continue
            ans += str(i)
        if not ans:
            return "0"
        else:
            # print(ans)
            return ans

    def comp(self, x):
        sum_len, sum_num = 0, ""
        for i in x:
            str_i = str(i)
            sum_len += len(str_i)
            sum_num += str_i
        if sum_num:
            return [-sum_len, -int("".join(sorted(sum_num, reverse=True)))]
        else:
            return [-sum_len, 0]
```


