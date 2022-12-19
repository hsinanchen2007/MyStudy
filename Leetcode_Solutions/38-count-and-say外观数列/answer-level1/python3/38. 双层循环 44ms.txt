### 解题思路
循环n-1次，求出每一次的结果（如果n=1，结果就是1）

### 代码

```python3
class Solution:
    def countAndSay(self, n: int) -> str:
        prev_person = '1'  #  设置前一个为1
        
        for i in range(1,n):  # 给定上一个数列，求下一个数列
            
            next_person, num, count = '', prev_person[0], 1  # 设置下一个数列为空，num为该数列循环过程中的上一个数，count为计数器
            
            for j in range(1,len(prev_person)):  #遍历上一个数列
                if prev_person[j] == num:  # 如果当前所指数与起所指的前一个数相等，计数器+1
                    count += 1
                else:  # 如果不相等
                    next_person += str(count) + num  # 将前一个数的个数与数值记录到下一个数列中
                    num = prev_person[j]  # 因为不相等，所以更新num为当前的数值
                    count = 1  # count也更新为1，重新开始计数
            
            next_person += str(count) +   # 更新next_person，其最后的两个数应该为上一个数列的最后一个数值以及其出现次数
            prev_person = next_person
        
        return prev_person
```