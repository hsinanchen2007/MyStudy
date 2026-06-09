### 解题思路
#### 方法一
把B赋到A的后面，然后排序。这个思路最好想到，但是浪费了A，B已经是有序数组这个条件，因此会想到方法二
#### 方法二
用两个指针遍历一遍A，B，每次把较小的数加入到额外开辟的list里。这个也不难想到，但是浪费了A后面的缓冲空间，因此有了方法三
#### 方法三
从尾部开始遍历A，B，每次选择较大的数字加入A的末端缓冲空间，这样就不开辟额外空间，也避免了从头遍历尾部数字被覆盖

### 易错点：
不用返回！双指针循环条件是or不是and！
### 代码

```python3
class Solution:
    def merge(self, A: List[int], m: int, B: List[int], n: int) -> None:
        # 方法三
        i,j,k=m-1,n-1,m+n-1
        while i>0 or j>=0:
            if i<0:
                A[k]=B[j]
                j-=1
            elif j<0:
                A[k]=A[i]
                i-=1
            elif A[i]>=B[j]: 
                A[k]=A[i]
                i-=1
            else:
                A[k]=B[j]
                j-=1
            k-=1
            
```