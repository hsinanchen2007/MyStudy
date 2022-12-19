第四题你们直接暴力搜每个字母表示的数字，不提前剪枝都过了吗。。

我来个复杂点不超时的剪枝方法。。乌龟 python 可过的
![image.png](https://pic.leetcode-cn.com/1b7057441396fb37802f753c6760fdc5d27c376f3a60bad5b546c6eb55e216f5-image.png)

比赛的时候暴力不剪枝不敢交，交的这个剪枝版本的

首先从个位开始，搜索每个字母代表的数组，确定所有words的个位后，result的个位数字直接能确定。
然后十位百位递推，中间如果出现result数字不相等的矛盾直接回退，这样剪枝可过，附代码


```python []
class Solution(object):
    def isSolvable(self, words, result):
        """
        :type words: List[str]
        :type result: str
        :rtype: bool
        """

        def reverse(s):
            ret = ""
            for i in range(len(s) - 1, -1, -1):
                ret += s[i]
            return ret

        data = [reverse(w) for w in words]  # 做数字反转
        data.append(reverse(result))

        n = len(data)  # 记多少个word，包括result
        m = len(result)  # 搜索的轮数（也就是个位、十位、百位等），这里有个问题没有注意，如果result比其中任何一个word短就直接判false
        s = {}  # 每个字母对应数字
        a = set()  # 哪些数字出现过

        # k表示搜索层数，根据k确定搜到第几轮的第几个word，n、m同上，y表示当前轮数各个words的累加和是多少
        def work(k, n, m, y):
            if k >= n * m:  # 搜到第m+1轮那就说明找到答案了
                return y == 0
            if (k + 1) % n == 0:  # 如果该计算result的当前位数字了
                if y == 0 and k // n == m - 1 and k // n > 0:  # 如果result最高位是前导0，判false
                    return False
                elif data[k % n][k // n] in s:  # 否则如果这个字母之前已经确定了，比较和当前结果是不是一致
                    if y % 10 == s[data[k % n][k // n]]:
                        return work(k + 1, n, m, y // 10)  # 注意把y的十位作为初始，带入下一轮
                    else:
                        return False
                else:  # 否则如果这个字母对应的数字直接确定成y%10，做判断
                    if y % 10 not in a:
                        a.add(y % 10)
                        s[data[k % n][k // n]] = y % 10
                        if work(k + 1, n, m, y // 10):  # 注意把y的十位作为初始，带入下一轮
                            return True
                        a.remove(y % 10)  # 回溯的时候记得把之前的结果干掉，否则不对
                        del s[data[k % n][k // n]]  # 回溯的时候记得把之前的结果干掉，否则不对
                    else:
                        return False
            elif k // n >= len(data[k % n]):  # 如果当前word长度不够当前轮，那么这位自动补0
                return work(k + 1, n, m, y)
            elif data[k % n][k // n] in s:  # 如果当前字母已经确定数字，直接判断
                if k // n > 0 and k // n == len(data[k % n]) - 1 and s[data[k % n][k // n]] == 0:  # 前导0判false
                    return False
                return work(k + 1, n, m, y + s[data[k % n][k // n]])
            else:  # 当前字母没有确定数组，枚举数字递归
                for i in range(10):
                    if k // n > 0 and k // n == len(data[k % n]) - 1 and i == 0:  # 前导0 continue
                        continue
                    if i not in a:
                        s[data[k % n][k // n]] = i
                        a.add(i)
                        if work(k + 1, n, m, y + i):
                            return True
                        a.remove(i)  # 回溯的时候记得把之前的结果干掉，否则不对
                        del s[data[k % n][k // n]]  # 回溯的时候记得把之前的结果干掉，否则不对
            return False

        return work(0, n, m, 0)
```

