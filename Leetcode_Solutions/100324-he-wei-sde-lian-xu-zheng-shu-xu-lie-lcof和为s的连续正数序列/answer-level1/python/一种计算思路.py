### 解题思路
此处撰写解题思路
循环target可以被求和的整数数量，如果被整除或者取余为0.5即存在结果

优先进行剪枝，判断target是否小于等于2，或者是否是否等于3（3可以不进行单独处理）。
之后进行循环操作，循环层数最多为target的一半并向上取整（主要处理5）。

循环中先判断循环i，i**2+i是否大于2*target，用于剪枝
接着获取target除以i的小数部分
如果为0.5，则说明有结果，且结果的长度为偶数，进行组合
如果为0，且i不为偶数，则说明有结果，进行组合


![image.png](https://pic.leetcode-cn.com/216225d98ba1502cdd9bb5beaebbddb27430b58f23235e2a9b7beab074f0fe54-image.png)




### 代码

```python3
class Solution:
    def findContinuousSequence(self, target: int) -> List[List[int]]:
        if target <= 2:
            return []
        if target == 3:
            return [[1, 2]]
        res = []
        for i in range(2, int(target / 2 + 1)):
            
            if (i ** 2 + i) > 2 * target:
                return res
            lack = (target / i) % 1
            if lack == 0.5:
                t = target / i
                tmp_res = []
                for j in range(1, int(i / 2) + 1):
                    tmp_res.append(int(t + j - 0.5))
                    tmp_res.append(int(t - j + 0.5))
                if min(tmp_res) <= 0:
                    return res
                tmp_res.sort()
                res.insert(0, tmp_res)
            elif lack == 0 and i%2!=0:
                t = int(target / i)
                tmp_res = [t]
                for j in range(1, int((i) / 2) + 1):
                    tmp_res.append(t + j)
                    tmp_res.append(t - j)
                tmp_res.sort()
                res.insert(0, tmp_res)
        return res
```