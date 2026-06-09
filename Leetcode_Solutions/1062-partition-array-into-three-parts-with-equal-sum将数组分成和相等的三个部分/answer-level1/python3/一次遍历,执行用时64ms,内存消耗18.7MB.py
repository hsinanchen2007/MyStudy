### 解题思路
1.判断数组长度,若数组长度小于3,直接返回False
2.对数组进行求和 sum
3.若sum % len(a) 余数不为0 ,直接返回False
4.对sum/3取整
5.遍历数组,对数组中存在sum/3的个数进行统计,若出现count等于2且当前遍历的位置不处于数组的最后一位,直接返回True
6.其他情况直接返回False

### 代码

```python3
class Solution:
    def canThreePartsEqualSum(self, A: List[int]) -> bool:
        if len(A) < 3:
            return False
        if sum(A) % 3 != 0:
            return False

        quotient = sum(A) // 3
        tmp = 0
        count = 0
        for index,value in enumerate(A):
            tmp = tmp + value
            if tmp == quotient:
                tmp = 0
                count = count + 1
            if count == 2 and index < len(A)-1:
                return True

        return False
```