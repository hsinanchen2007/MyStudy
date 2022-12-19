### 解题思路
1. 不采用排序,考虑到扑克只有14种类型,建立对应的字典
2. 提取大小王的牌数
3. 遍历字典,取出开始的牌号begin,结束的牌号end,和begin与end之间的牌数mid
4. 在大小王+mid牌数为5,并且最大的牌与最小的牌差小于5,则证明顺子

### 代码

```py
class Solution:
    def isStraight(self, nums: List[int]) -> bool:
        if (not nums) or len(nums) < 5: return False
        dic = {i: 0 for i in range(0, 14)}   #建立对应的字典
        for i in range(0, len(nums)):
            dic[nums[i]] += 1
        count = dic[0]            
        begin,end,mid = 0,0,0
        #取出开始的牌号begin,结束的牌号end,和begin与end之间的牌数mid
        for i in range(1, 14):
            if dic[i] != 0:
                if not begin:
                    begin = i
                mid += 1
                end = i

        # 在大小王+mid牌数为5,并且最大的牌与最小的牌差小于5,则证明顺子
        if mid + count == 5 and end - begin < 5:
            return True
        else:
            return False
```