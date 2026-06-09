### 解题思路
双指针

### 代码

```python3
class Solution:
    def merge(self, A: List[int], m: int, B: List[int], n: int) -> None:
        """
        Do not return anything, modify A in-place instead.
        """
        # 有序部分的大小
        num_size=m
        # A的指针的起始位置
        start=0
        for i in B:
            # 用于判断是否插在尾部
            flag=False
            # 遍历查找位置
            for j in range(start,num_size):
                if A[j]<i:
                    continue
                else:
                    # 往后挪，插入
                    for x in range(num_size,j,-1):
                        A[x]=A[x-1]
                    A[j]=i
                    num_size+=1
                    # 更新起始点位置
                    start=j
                    flag=True
                    break
            # 尾部插入
            if flag==False:
                A[num_size]=i
                num_size+=1
                start=num_size

                    
```