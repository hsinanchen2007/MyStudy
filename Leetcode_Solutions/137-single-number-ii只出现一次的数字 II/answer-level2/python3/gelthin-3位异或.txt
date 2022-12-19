### 解题思路
看到了评论 [陈牧远](https://leetcode-cn.com/problems/single-number-ii/comments/) 的第一条回复下引用的例子 [Grandyang](https://www.cnblogs.com/grandyang/p/4263927.html) 竟然把所有 leetcode 全部刷完，惊呆！大丈夫当如是哉！

采用异或的方法， 基本思路是用两个 bit 位来代表三次变化， 但需要如下变化 00->01->10->00


看了题解排序第一条[Single Number II（模拟三进制法，图表解析）](https://leetcode-cn.com/problems/single-number-ii/solution/single-number-ii-mo-ni-san-jin-zhi-fa-by-jin407891/) 下的第一条回复，发现有另外一种解释

``` python3
class Solution:
    def singleNumber(self, nums: List[int]) -> int:
        b1,b2 = 0,0#出现一次的位，和两次的位
        for n in nums:
            b1 = (b1 ^ n) & ~ b2 #既不在出现一次的b1，也不在出现两次的b2里面，我们就记录下来，出现了一次，再次出现则会抵消
            b2 = (b2 ^ n) & ~ b1 #既不在出现两次的b2里面，也不在出现一次的b1里面(不止一次了)，记录出现两次，第三次则会抵消
# 若第三次出现， 则由于 b2=1, 导致 b1 =0 ,b2 =0
        return b1
```


### 代码

```python3
class Solution:
    def singleNumber(self, nums: List[int]) -> int:
        
        #  ab, 都是整数, 由于下面是位运算, 各位之间不相关，不妨设 a， b 都仅表示 1 位 2 进制 bit
        # 设 b 代表第 2 位， a 代表第 1 位
        # 00 -> 01 - 10 -> 00  期望按如下规则，当 某一位出现，变为 01, 出现三次，则变为 00
        a, b = 0, 0
        for num in nums: # 不妨只看某一位，设 num = 1 bit 1
            b = (b^num) & ~a  # b 先处理，因为 b 先运算
            a = (a^num) & ~b
        
        return b  # 返回 b，因为出现 1 此，恰好 b 为 1， 而 a 为 0
        

```