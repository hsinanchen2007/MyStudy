### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int minIncrementForUnique(vector<int>& A) {
        int count =0;
        sort(A.begin(),A.end());
        for(int i=1;i<A.size();i++){
            if(A[i]<=A[i-1]){
                int temp=A[i-1]-A[i]+1;
                A[i]=A[i]+temp;
                count+=temp;
            }
        }
        return count;
    }
};
```