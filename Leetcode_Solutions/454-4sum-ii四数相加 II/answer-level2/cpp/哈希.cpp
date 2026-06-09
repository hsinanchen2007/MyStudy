### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        map<int,int> ab;
        for(int i=0;i<A.size();i++){
            for(int j=0;j<B.size();j++){
                ab[A[i]+B[j]]++;
            }
        }
        map<int,int> cd;
        for(int i=0;i<C.size();i++){
            for(int j=0;j<D.size();j++){
                cd[C[i]+D[j]]++;
            }
        }
        int ans=0;
        for(auto it=ab.begin();it!=ab.end();it++){
            int c=it->first;
            if(cd.find(-c)!=cd.end()){
                ans+=cd.find(-c)->second*it->second;
            }
        }
        return ans;
    }
};
```