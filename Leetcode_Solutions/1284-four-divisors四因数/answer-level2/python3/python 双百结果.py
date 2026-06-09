### 解题思路
还是存在疑惑。
为什么8是，而16不是。
我这里计算的时候，认为满足要求的有两种:
1 素数 * 素数 的结果
2 素数的3次方的结果 --- [根据题目推算出来的]--不是很认同

### 代码

```python3
class Solution:
    def __init__(self):
        self._real = []
        self.init()
    def get_s(self):
        # 获取0=>100000的素数
        mmax = 100010
        
        res = [True] * mmax
        res[0] = False
        for i in range(2, mmax//2+1):
            for j in range(2, i+1):
                if i * j >= len(res):
                    break
                res[i*j] = False
        real_res = []
        for i in range(mmax):
            if res[i]:
                real_res.append(i)
        return real_res
    
    def init(self):
        mmax = 100010
        res = self.get_s()
        # print(len(res))
        self.real = [0] * mmax
        for i in range(1, len(res)):
            for j in range(1, i):
                if res[i] * res[j] > mmax:
                    break
                if self.real[res[i] * res[j]] > 0:
                    self.real[res[i]*res[j]] = 0
                else:
                    self.real[res[i]*res[j]] = res[i] + res[j] + res[i] * res[j] + 1
                    
        for i in range(1, len(res)):
            # 平方和3次方
            num = res[i] * res[i] * res[i]
            if num > mmax:
                break
            self.real[num] = 1 + num + res[i] * res[i] + res[i]
            # num *= res[i]
            # if num > mmax:
            #     continue
            # self.real[num] = 1 + num + res[i] * res[i]*res[i] + res[i]
        
    def sumFourDivisors(self, nums: List[int]) -> int:
        res = 0
        for num in nums:
            res += self.real[num]
        return res
```