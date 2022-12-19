### 解题思路
此处撰写解题思路
内存消耗 :
13.3 MB
, 在所有 Python3 提交中击败了
100.00%
的用户
### 代码

```python3
class Solution:
    def findContinuousSequence(self, target: int) -> List[List[int]]:
        ans=[]
        num_list=[]
        b=1
        while b <= target:
            a=b
            t=target
            while t-a >= 0:
                num_list.append(a)
                t -=a
                a +=1
            if sum(num_list) == target and len(num_list) > 1:
                ans.append(num_list)
                num_list=[]
            else:
                num_list=[]
            b +=1
        
        return ans
        

```