### 解题思路
先计算整个数组的和，然后除3，如果能整除的话，另整除的结果为 Third_1 。
然后开始遍历数组，累计求前i个元素的和为tem_sum。一旦Third_1=tem_sum.此时记住这个i并且把tem_sum重置为0。
那么就开始从i=1个元素开始又进行往后遍历求和,如果又出现Third_1=tem_sum，那么再记住此时的i。
最后求剩下元素的和。

### 代码

```python3
class Solution:
    def canThreePartsEqualSum(self, A: List[int]) -> bool:
        A_len = len(A)
        list1 = []
        if sum(A)%3 ==0:  #确保数组的和除以3的结果为整数
            Third_1 = sum(A) / 3
            tem_sum = 0
            for i in range(A_len):
                tem_sum += A[i]
                if tem_sum == Third_1: #第一次和第二次遍历数组求和时满足 tem_sum == Third_1的话就把这个tem_sum添加到空列表中去
                    list1.append(tem_sum)
                    tem_sum = 0
                    if len(list1) == 2 and i != A_len-1: #i != A_len-1的意思是i不能等于A的最后一个数字的索引
                        c = sum(A[i+1:])
                        list1.append(c)
                        return list1[1] == list1[0] ==list1[2]
        return False
```