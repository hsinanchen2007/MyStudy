### 解题思路
> 注意此题是划分, 找出位置并划分即可, 不是让把数据中的元素随机挑选出来分类成3部分; 如果要确认是否能挑选并归为和相等的三类难度会大大提高;

此题要求数据切2刀,分成3个子数组, 故直接去找出可以划分的点位即可;具体步骤如下:
- 1. 先求和s判定是否能被3整除;
- 2. 找出每一份的子和, 即找出 s//3 的值;
- 3. 查找等分点, 直接遍历一次, 用累加的方式比较好, 不能直接判断是否可以整除, 需要防止和为0的情况, 整除就挂了或者判定起来代码复杂.
- 4. 判定是否可以成功划分成3等分, 此处用的判定```count > =3```的方式,为了防止和为0的特殊情况;


### 代码

```python3
class Solution:
    def canThreePartsEqualSum(self, A: List[int]) -> bool:
        total = sum(A)
        if total % 3:
            return False
        target = total // 3
        count = 0
        temp = 0
        for i in A:
            temp += i
            if temp == target:
                count += 1
                temp = 0

        return count >= 3
```

### 运行结果
```
执行用时 :72 ms, 在所有 Python3 提交中击败了96.60%的用户
内存消耗 :18.7 MB, 在所有 Python3 提交中击败了98.29%的用户
```