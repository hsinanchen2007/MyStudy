### 解题思路
1. 统计ablon每个字母出现的次数；
2. 返回字母出现频数最小的频数
3. 难点在于：l和o都出现两次；

![image.png](https://pic.leetcode-cn.com/ef998c205c4357b9087eff7c5b76da587891129cc4bada3892a6e11783f67b31-image.png)

### 代码

```python3
class Solution:
    def maxNumberOfBalloons(self, text: str) -> int:
        setT = set(text)
        
        if 'a' not in setT or 'b' not in setT or 'l' not in setT or 'n' not in setT or 'o' not in setT:  # 是否有简写方式？利用all()？
            return 0
        
        textC = collections.Counter(text)
        res = []
        for key, value in textC.items():
            if key in 'ablon':
                res.append(value)
        
        minC = min(res) # 出现次数最少的
        twiceL = textC.get('l') 
        twiceO = textC.get('o')

        minOL = min(twiceL,twiceO)  # l和o那个出现次数少
        if minC * 2 <= minOL:       # 两倍minC和l/o中最少次数的那个进行比较，
            return minC             # 如果minC*2更小，则说明l和o中出现更少的那个也可以覆盖minC次
        else:
            return minOL // 2       # l o次数不能覆盖minC，那么只能组成o和l中更少次数的一半

```