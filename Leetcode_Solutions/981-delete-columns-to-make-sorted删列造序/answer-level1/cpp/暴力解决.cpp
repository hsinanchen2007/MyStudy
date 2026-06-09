### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int minDeletionSize(vector<string>& A) {
        int ans=0;
        for(int i=0;i<A[0].size();i++){
            int max1=A[0][i];
            int j;
            for(j=0;j<A.size();j++){
                if(A[j][i]<max1){
                    break;
                }
                max1=A[j][i];
            }
            if(j<A.size()){
                ans++;
            }
        }
        return ans;
    }
};
```