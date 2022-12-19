### 解题思路
最笨的方法，A,B中加索引，按照索引位置进行比较，将B中元素插入A中正确的位置

### 代码

```python3
class Solution:
    def merge(self, A: List[int], m: int, B: List[int], n: int) -> None:
        """
        Do not return anything, modify A in-place instead.
        """
        i=0  #标记A中的索引
        j=0  #标记B中的索引
        k=0  #标记当前元素位于初始A中的位置
        while(True):
            if(n==0):
                break  #若B为空，结束
            if(m==0):
                A[i:]=B[j:]  #若A为空，将B复制给A
                break
            if(j==n):
                break #防止B越界
            if k==m:
                A[i:]=B[j:]  #若k==m，则说明比较元素到达原始A的末尾，直接将B复制即可
                break
            elif A[i]<B[j]:
                i+=1
                k+=1
                continue  #若A当前元素小于B当前元素，将A的位置向后移，同事将k向后移
            else:
                A.insert(i,B[j])
                A.pop()
                j+=1
                i+=1
                continue  #若A当前元素不小于B当前元素，则将B当前元素插入A当前位置，然后pop掉A末尾的一个0，保持A长度不变，B向后移动一个位置，A也向后移动一个位置，但是k不变，因为A插入一个元素
```