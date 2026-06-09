### 解题思路
暴力法解，依次给每个位置+1，但注意要判断给的糖果是否已经超过了剩余的糖果数，要赋值剩余糖果的时候也应当注意是否还大于0。
看了题解，感觉代码写得十分简洁。要注意的有：
1、可以用result = [0]*num_people而不是一一赋值
2、直接取剩余糖果和当前应当分的最小值
3、用i%num_people，而不是用for循环
### 代码

```python
class Solution(object):
    def distributeCandies(self, candies, num_people):
        """
        :type candies: int
        :type num_people: int
        :rtype: List[int]
        """
        result = []
        for people_id in range(num_people):
            result.append(0)
        totalnum_candies = candies
        candie_num = 1
        while totalnum_candies>=0:
            for people_id in range(num_people):
                if totalnum_candies>=candie_num:
                    result[people_id] = result[people_id] + candie_num
                elif totalnum_candies>0:
                    result[people_id] = result[people_id] + totalnum_candies
                totalnum_candies = totalnum_candies - candie_num
                candie_num = candie_num + 1
        return result

```