### 解题思路
这道题可以采用多种解法，
+ 1. 模拟分配的过程，逐个遍历，while candies>0: ...
+ 2. 先计算出 left, 使得， (left+1)*left/2 <= candies < (right+1)*right/2, tmp = candies - (left+1)*left/2, 然后枚举 range(1, left+1), 这个每个小孩分糖果数
+ 3. 直接全部计算出来， 对于每个 ans[i] 来说，都是一个等差数列，公差为 +people, 只是项数需要仔细计算。



### 代码

```python3
class Solution:
    def distributeCandies(self, candies: int, num_people: int) -> List[int]:
        # 二分搜索
        if num_people == 1:
            return [candies]

        left, right = 1, candies//2
        while left<right:
            mid = (left+right+1)//2
            if (mid+1)*mid/2 > candies:  # 最后一个 <= candies 的值  # 若是搜索第一个大于candies， 则从左边排除
                right = mid-1
            else:
                left = mid
        tmp = candies - (left+1)*left/2  # 可能有多余的
        
        ans = [0]*num_people
        # 有规律的长度
        leng = left
        num_group = leng//num_people
        rest = leng % num_people
        for i in range(num_people):
            if i < rest:
                k = num_group+1
            else:
                k = num_group
            ans[i] = (i+1)*k + k*(k-1)//2*num_people
        if tmp > 0:
            ans[rest] += int(tmp)
        return ans

class Solution:
    def distributeCandies(self, candies: int, num_people: int) -> List[int]:
        # 二分搜索
        if num_people == 1:
            return [candies]

        left, right = 1, candies//2
        while left<right:
            mid = (left+right+1)//2
            if (mid+1)*mid/2 > candies:  # 最后一个 <= candies 的值  # 若是搜索第一个大于candies， 则从左边排除
                right = mid-1
            else:
                left = mid
        tmp = candies - (left+1)*left/2
        if  tmp > 0:
            result = list(range(1, left+1)) + [tmp]
        else:
            result = list(range(1, left+1))
        ans = [0]*num_people
        i = -1
        for x in result: # 这里有一个大循环，太花费时间。
            i = (i+1)%num_people
            ans[i] += int(x)

        return ans



```