### 解题思路
假如n=3那么初始值为000111  ,每次都加2，因为要保证最后一位一定是1，
最大值一定是010101，超过这个就一定不满足，作为结束的条件，
不超过的也可能不满足，所以还要判断一次。最终把0换成（1换成）返回结果即可。
### 代码

```python3

class Solution:

    def generateParenthesis(self, n: int) -> List[str]:
        """方法二  二进制的方式"""
        if n == 1:
            return ["()"]
        start = "0" * n + "1" * n
        result = list()
        result.append(start)
        maxstr = "01" * n
        maxValue = int(maxstr, 2)
        while True:
            # cur = int(int(start, 2) + 0b10, 2)
            cur = int(start, 2) + 2
            if cur == maxValue:
                result.append(maxstr)
                break
            start = bin(cur)[2:]
            if start.count("1") != n:
                continue
            else:
                cur = "0" * (2 * n - len(start)) + start
                # 判断cur是不是符合要求
                flag = True
                v = 0
                for i in cur:
                    v += 1 if i == "0" else -1
                    if v < 0:
                        flag = False
                        break
                if flag:
                    result.append(cur)
        return [i.replace("0", "(").replace("1", ")") for i in result]

```