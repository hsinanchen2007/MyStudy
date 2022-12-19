### 解题思路
对于B[i]，对应A[]中比B[i]大的最小值，若不存在，则对应A[]中的最小值

### 代码

```cpp
class Solution {
public:
    vector<int> advantageCount(vector<int>& A, vector<int>& B) {
        vector<int> res,flag;
        sort(A.begin(),A.end());
        for(int i=0;i<A.size();i++)
            flag.push_back(0);
        for(int i=0;i<B.size();i++){
            int j;
            for(j=0;j<A.size();j++)
                if(A[j]>B[i]&&flag[j]==0){
                    res.push_back(A[j]);
                    flag[j]=1;
                    break;
                }
            if(j==A.size())
                for(int k=0;k<A.size();k++)
                    if(flag[k]==0){
                        res.push_back(A[k]);
                        flag[k]=1;
                        break;
                    }
        }
        return res;
    }
};
```