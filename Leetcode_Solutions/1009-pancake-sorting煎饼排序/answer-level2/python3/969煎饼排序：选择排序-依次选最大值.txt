### 解题思路
1.找出前n个值的最大值索引k
2.反转前k+1个元素将最大值移到最前边(若k=0则省略该步)
3.反转0-n个元素将最大元素移动至后面
4.n-=1,回至1，直到n=1（只有1个元素时不用进行操作）

### 代码

```python3
class Solution:
    def pancakeSort(self, A: List[int]) -> List[int]:
        def tranv(A,index):#反转前k个数
            k=[]
            for i in range(index+1):
                k.append(A[i])
            for i in range(index+1):
                A[i]=k.pop()
            return None
        n=len(A)
        ans=[]
        for i in range(n):
            if n>1:
                index,_=max(enumerate(A[:n]),key=lambda x:x[1])#找到前n个数的最大的索引
                if index >0:
                    tranv(A,index)#前index+1个数反转
                    ans.append(index+1)
                tranv(A,n-1)
                ans.append(n)
                n-=1
            else:break
        return ans





```