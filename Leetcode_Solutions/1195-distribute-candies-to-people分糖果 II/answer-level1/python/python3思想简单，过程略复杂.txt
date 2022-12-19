### 解题思路
首先你不知道他要循环几次，所以用一个while True
然后就是添加条件

### 代码

```python3
class Solution:
    def distributeCandies(self, candies: int, num_people: int):
        ans = [0] * num_people
        index = 0
        temp = 1
        while True:
            if candies == 0:#条件1：糖果分完了，返回
                break
            if index == num_people:#条件2：分完了一轮，还有剩余，需要从头分剩下的糖果
                index = 0

            if candies >= temp:#条件3：temp是每个小朋友按算法该拿到的数量，但是如果剩下糖果不够这个数量，就把剩下的都给他，判断一下即可
                candies = candies - temp
                ans[index] += temp
            else:
                ans[index] += candies
                break
            index += 1#两个中间变量一个是列表索引，保正列表循环，第二个是下一个小朋友应分糖果数
            temp += 1
        return ans
```