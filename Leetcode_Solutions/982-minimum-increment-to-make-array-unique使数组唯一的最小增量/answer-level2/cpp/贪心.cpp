### 解题思路
一开始想到最蠢的办法就是先排序，然后逐个比较每个元素是否出现过，如果出现过就不停地给他+1直到没出现，一交发现**超时**了，然后就想到完全没必要不停地+1，可以在出现后一个数不大于前一个数的时候，让后一个数加上（前一个数+1-后一个数），即让后一个数比前一个数大1即可

### 代码

```cpp []
class Solution {
public:
    int minIncrementForUnique(vector<int>& A) {
        sort(A.begin(),A.end());
        int ans=0;
        for(int i=1;i<A.size();++i){
            if(A[i]<=A[i-1]){
                ans+=A[i-1]+1-A[i];
                A[i]+=A[i-1]+1-A[i];
            }
        }
        return ans;
    }
};
```
```python []
class Solution(object):
    def minIncrementForUnique(self, A):
        """
        :type A: List[int]
        :rtype: int
        """
        A.sort()
        ans=0
        for i in range(1,len(A)):
            if A[i-1]>=A[i]:
                ans+=A[i-1]+1-A[i]
                A[i]+=A[i-1]+1-A[i]
        return ans
```