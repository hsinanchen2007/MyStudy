### 解题思路
  思路还是比较好理解的吧 
  先查找到所有能出发的位置。然后在从每个可以出发的位置开始，
  判断剩余的油量

### 代码

```python3
class Solution:
    def canCompleteCircuit(self, gas: List[int], cost: List[int]) -> int:
        if not gas or not cost:
            return 0
        '''
            这些题 是真的tmd难啊  还是要多做做题！要么原题都没思路！！！
            这个题很抽象啊  但是一画图就明白了
        '''
        # 首先可以找到 适合出发的位置
        arr = []
        for i in range(len(gas)):
            if gas[i] >= cost[i]:
                arr.append(i)
        # arr里面就全部都是可行的地址
        for i in arr:
            left = 0
            j = i
            flag = True
            for _ in range(len(gas)):
                left += gas[j] - cost[j]
                if left < 0:
                    flag = False
                    break
                if j + 1 == len(gas):
                    j = 0
                else:
                    j += 1
            if flag:
                return i
        return -1
```