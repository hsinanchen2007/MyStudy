### 解题思路
排序遍历，若某位小于等于前一位，增量为使其比前一位大1的值，将值累加即为答案

### 代码

```cpp
class Solution {
public:
    int minIncrementForUnique(vector<int>& A) {
        sort(A.begin(),A.end());
        int ans=0;
        for(int i=1;i<A.size();i++)
            if(A[i]<=A[i-1]){
                ans+=A[i-1]-A[i]+1;
                A[i]=A[i-1]+1;
            }
        return ans;
    }
};
```