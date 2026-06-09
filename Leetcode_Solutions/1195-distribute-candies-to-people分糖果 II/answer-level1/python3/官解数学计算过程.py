### 解题思路
详见官解，这里写了下数学计算过程，希望对大家有用。
![微信图片_20200313222222.jpg](https://pic.leetcode-cn.com/555eea53cfefb8abbad64043aec5e64ce844aade58f288bb10ffbe7e478b6a57-%E5%BE%AE%E4%BF%A1%E5%9B%BE%E7%89%87_20200313222222.jpg)


### 代码

```python3
class Solution:
    def distributeCandies(self, candies: int, num_people: int) -> List[int]:
        ans = [0]*num_people
        # 获得完整礼物的人数 p
        p = int((2*candies + 0.25)**0.5 - 0.5)
        # 完整部分分发
        rows = p // num_people
        cols = p % num_people
        for i in range(num_people):
            ans[i] = (i+1)*rows + int(num_people*rows*(rows-1)/2)
            # 不完整部分分发
            if i < cols:
                ans[i] += (i+1) + num_people*rows
        # 剩余分发
        ans[cols] += candies - int(p*(p + 1)/2)
        
        return ans


```