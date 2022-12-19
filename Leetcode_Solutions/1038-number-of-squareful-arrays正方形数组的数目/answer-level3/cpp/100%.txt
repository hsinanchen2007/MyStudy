### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int numSquarefulPerms(vector<int>& A) {
        set<vector<int>> s;
        vector<int> v;
        sort(A.begin(),A.end());
        vector<bool>visited(A.size(),false);
        numSquare(A,s,v,visited);
        return s.size();
    }
    void numSquare(vector<int> &A,set<vector<int>> &s,vector<int>&v,vector<bool>&visited){
        if(v.size()==A.size()){
            int i;
            for(i=1;i<v.size();i++){
                int t=sqrt(v[i]+v[i-1]);
                if(v[i]+v[i-1]!=t*t){
                    break;
                }
            }
            if(i==v.size()){
                s.insert(v);
            }
            return;
        }
        for(int i=0;i<A.size();i++){
            if(visited[i])continue;
            if(i>0&&A[i-1]==A[i]&&visited[i-1]==false)
            {
                continue;
            }
            if(v.size()>0){
                int t=sqrt(A[i]+v[v.size()-1]);
                if(A[i]+v[v.size()-1]!=t*t){
                    continue;
                }
            }
            v.push_back(A[i]);
            visited[i]=true;
            numSquare(A,s,v,visited);
            v.pop_back();
            visited[i]=false;
        }
    }
};
```