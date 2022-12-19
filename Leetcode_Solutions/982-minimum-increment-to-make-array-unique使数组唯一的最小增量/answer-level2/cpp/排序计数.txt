### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int minIncrementForUnique(vector<int>& A) {
        if(A.size()==0)return 0;
        sort(A.begin(),A.end());
        int ans=0;
        for(int i = 1; i < A.size(); ++i){
           if(A[i]<=A[i-1])
           {
               int pre = A[i];
               A[i] = A[i-1]+1;
               ans+=A[i]-pre;
           }
        }
        return ans;
    }
};
```