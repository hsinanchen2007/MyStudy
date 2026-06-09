直接查看原来的每列的数据是否具有一定的顺序，然后对其计数，最后计算出需要删减多少列
```
class Solution:
    def minDeletionSize(self, A: List[str]) -> int:
        num=0
        lenth1=len(A)
        lenth2=len(A[0])
        list1=[]
        for j in range(lenth2):
            for i in range(lenth1):
                list1.append(A[i][j])
            index_list=sorted(list1)
            if index_list==list1:
                num+=1
            list1=[]
        return lenth2-num

```
