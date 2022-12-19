### 解题思路
此处撰写解题思路
因为连续求和公式 sum = （首项+尾项）*项数/2
所以假如target可以分成N个数相加
target = x + (x+1) + (x+2) + (x+3) + (x+4) + ..... +(x+n-1)
       = nx + （0+1+2+3+4+...+n-1）
       = nx + (n-1)*n/2
所以 x = (target - (n-1)*n/2)/n   X即代码里的Y
### 代码

```python3
class Solution:
    def findContinuousSequence(self, target: int) -> List[List[int]]:
        A = []
        max1 = int(target/2)+1 #连续整数求和 
        for i in range(max1,1,-1): #因为题目输出是先大后小的数组，所以采用倒叙方法
            x = (target-(i-1)*i/2)%i #X为判定条件 能除尽证明可以连续求和
            y = (target-(i-1)*i/2)/i #Y为起始位置
            if x==0 and y>0: #这里吃了亏，如果Y不大于0 那么也存在负数开始一直加到整数的连续整数求和
                B = []
                for j in range(int(y),int(y+i)): #将 i个连续的书输入B里
                    B.append(j)
                A.append(B)#输入A里
            else:
                continue
        return A
        
        
```