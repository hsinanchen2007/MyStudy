### 解题思路
执行用时 :20 ms, 在所有 Python 提交中击败了88.51%的用户
内存消耗 :11.8 MB, 在所有 Python 提交中击败了13.51%的用户

首先初始化数组
按规则分糖果，记录已分糖果总数n和次数ln
注意判断条件：
1.ln<=人数时，ans[ln]得到糖果
2.ln>人数时，取ln/num_pepole的余数，ans[余数]得到糖果
3.最后一次分糖果
直到分完糖果

### 代码

```python
class Solution(object):
    def distributeCandies(self, candies, num_people):
        """
        :type candies: int
        :type num_people: int
        :rtype: List[int]
        """
        n = 0
        a = 0
        ln = 0
        ans = [0 for x in range(num_people)]
        while True:
            if n == candies:
                return ans
            elif n > candies:
                a = candies - n + a
                if ln >= num_people:
                    ans[ln % num_people] += a
                else:
                    ans[ln] += a
                return ans
            else:
                a += 1
                n += a
                if n > candies:
                    a = candies - n + a
                    n = candies
                if ln >= num_people:
                    ans[ln % num_people] += a
                else:
                    ans[ln] += a
                ln += 1     
```