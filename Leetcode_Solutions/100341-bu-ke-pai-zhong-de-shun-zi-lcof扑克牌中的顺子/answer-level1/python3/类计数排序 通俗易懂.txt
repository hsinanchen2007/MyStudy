### 解题思路
与计数排序相似，但只需统计每个元素的出现情况即可

### 代码

```
class Solution:
    def isStraight(self, nums: List[int]) -> bool:
        zeroNum = 0  # 0的个数
        store = [0 for _ in range(14)]  # 统计牌的种类
        for n in nums:  # 类计数排序
            if n == 0:
                zeroNum += 1
            else:
                if store[n] == 0:
                    store[n] = 1
        
        cur_sum= 0
        for i in range(len(store)):
            if store[i] == 1:
                curNum = sum(store[i:i+5])
                break
        return True if curNum + zeroNum == 5 else False


```
### 复杂度
时间复杂度O(n)
空间复杂度O(1)