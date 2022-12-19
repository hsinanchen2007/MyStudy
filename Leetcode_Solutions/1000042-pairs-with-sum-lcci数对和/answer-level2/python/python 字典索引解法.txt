### 解题思路
**字典索引解决**
1. 主要思想是考虑对每一个数字建立字典，然后遍历一次数组，对数字进行计数（对数组数字建立字典）
2. 再遍历一次数组，将符合要求的数值对加入到结果当中（主要是字典当中要有符合的数字大于1，且符合的数字存在于字典当中）

------------------------

PS：考虑一个特殊情况，如果是target等于当前数字的2倍，
```
if target - i != i:
```
，则需要考虑此时字典中的数字是否大于2才能加入数值对到结果当中

![image.png](https://pic.leetcode-cn.com/66830711126b943213e697d013ea72a120926eb31cf105a0d925affbc2f7cc51-image.png)



### 代码

```python3
class Solution:
    def pairSums(self, nums: List[int], target: int) -> List[List[int]]:
        all_dic = {}
        for i in nums:
            if i in all_dic:
                all_dic[i] += 1
            else:
                all_dic[i] = 1

        res = []

        for i in nums:
            if all_dic[i] > 0 and ((target - i) in all_dic and all_dic[target-i] > 0):
                if target - i != i:
                    temp = [i,target-i]
                    all_dic[i] -= 1
                    all_dic[target-i] -= 1
                    res.append(temp)
                else:
                    if all_dic[i] > 1:
                        temp = [i, target - i]
                        all_dic[i] -= 1
                        all_dic[target - i] -= 1
                        res.append(temp)
        return res
```