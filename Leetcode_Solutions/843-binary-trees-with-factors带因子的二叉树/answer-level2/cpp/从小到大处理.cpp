### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& A) {
        sort(A.begin(),A.end());
        map<int,long long int>m;
        int ans=0;
        for(int i=0;i<A.size();++i){
            m[A[i]]=1;
            for(int j=0;j<i;++j){
                if((A[i]%A[j]==0)&&m.count(A[i]/A[j])){
                    int temp=A[i]/A[j];
                    if(temp<A[j])break;
                    if(A[j]==temp)
                        m[A[i]]+=(m[A[j]]*m[A[i]/A[j]]);
                    else
                        m[A[i]]+=(m[A[j]]*m[A[i]/A[j]])*2;
                }
            }
            ans=(ans+m[A[i]])%1000000007;
        }
        return ans;
    }
};
```