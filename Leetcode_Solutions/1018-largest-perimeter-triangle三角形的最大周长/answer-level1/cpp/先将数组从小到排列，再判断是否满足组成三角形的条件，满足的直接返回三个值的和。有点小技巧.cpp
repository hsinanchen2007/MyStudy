### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int largestPerimeter(vector<int>& A) {
        sort(A.begin(),A.end());
        int len=A.size()-1;
        for(int i=len;i>0;i--){
            if(i>1&&A[i]-A[i-1]<A[i-2]&&A[i-1]+A[i-2]>A[i])
            return A[i]+A[i-1]+A[i-2];
        }
        return 0;
    } 
};
```