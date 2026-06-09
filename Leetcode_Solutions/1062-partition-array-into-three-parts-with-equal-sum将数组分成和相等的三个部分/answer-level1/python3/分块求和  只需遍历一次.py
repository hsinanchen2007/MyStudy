### 解题思路
此处撰写解题思路
    根据题意，给定数组A 需要划分成三个相等的非空部分时返回true
    所以可以得到以下条件
     1. 如果数组长度小于 3 返回 Flase
     2. 如果数组和不能被 3 整除 返回 Flase
     3. 如果数组不能被分成相等的 3 块 返回 Flase
     4. 如果以上均能满足 返回true
     关键部分是 如何知道该数组能被分成三块
     
    三等分的和为 sumA//3 所以只需要循环一次 每次求得一块和为sumA 块数time+1
    如果块数大于等于 3 则 返回 true
    注意：可能会有sumA//3 = 0的情况，该情况只要块数大于等于3，就能分成三等分
    


### 代码

```python3
class Solution:
    def canThreePartsEqualSum(self, A: List[int]) -> bool:
        len_A = len(A)
        sumA  = sum(A)
        if len_A < 3:
            return False
        elif sumA % 3 != 0:
            return False
        else:
            sumA = sumA // 3
            time = 0
            sum3 = 0
            for i in A:
                sum3 += i
                if sum3 == sumA:
                    time += 1
                    sum3 =0
            if time >= 3:
                return True
            else:
                return False

```