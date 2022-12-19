### 解题思路
此处撰写解题思路
主要思想：利用两个数组，将每个位置的状态设置为当前位置的之前的乘积和与当前位置的之后的乘积和。主要是还是利用了“状态”的思想。
### 代码

```python3
class Solution:
    def constructArr(self, a: List[int]) -> List[int]:
        ans=[]
        LR,RL=[1]*len(a),[1]*len(a)
        for i in range(1,len(a)):
            LR[i]=LR[i-1]*a[i-1]
        for j in range(len(a)-2,-1,-1):
            RL[j]=RL[j+1]*a[j+1]
        for k in range(len(a)):
            ans.append(LR[k]*RL[k])
        return ans

```