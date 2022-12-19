### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int largestPerimeter(vector<int>& A) {
        if(A.size()<=2)return 0;
        sort(A.begin(),A.end());
        int len=A.size();
        for(int i=len-1;i>=2;)
        {
            if(A[i-2]+A[i-1]>A[i])
                return A[i-2]+A[i-1]+A[i];
            else
                i--;
        }
        return 0;
    }
};
```