### 解题思路
这种题型一般是先排序，然后根据类似两个指针的方式后移的方式得到求解。

### 代码

```python3
class Solution:
    def fairCandySwap(self, A: List[int], B: List[int]) -> List[int]:
        A.sort()
        B.sort()
        def get_sum(A):
            return sum(A)
        def get_num_val(A,B):
            ans=[]
            sum_A=get_sum(A)
            sum_B=get_sum(B)
            sum_ab=sum_A+sum_B
            sum_ab=int(sum_ab/2)
            dval=sum_ab-min(sum_A,sum_B)
            min_arry = A if sum_A<sum_B else B
            max_array=A if sum_A>sum_B else B
            m =len(min_arry)
            n=len(max_array)
            i=0
            j=0
            while(i<m and j<n):
                if (max_array[j]-min_arry[i]==dval):
                    return ans+[min_arry[i]]+[max_array[j]] if sum_A<sum_B else ans+[max_array[j]]+[min_arry[i]]
                elif max_array[j]-min_arry[i]>dval:
                    i=i+1
                else :
                    j=j+1
        return (get_num_val(A,B))
```