### 解题思路
此处撰写解题思路
1. 先判断A的元素个数
2. 判断A元素和是否被3整除
3. 遍历A，各元素相加，如果和为所有元素的1/3，则符合条件，再重新相加
4. 判断符合条件的数量是否大于3
5. 最后判断剩余的元素和是否等于0
### 代码

```python3
class Solution:
    def canThreePartsEqualSum(self, A: List[int]) -> bool:
        if len(A) < 3:
            return False
        s = sum(A)
        if s%3 != 0:
            return False
        result = 0
        i = 0
        for one in A:
            result += one
            if result == s//3:
                result = 0
                i += 1
        if i < 3:
            return False
        if result != 0:
            return False
        else:
            return True
        
```