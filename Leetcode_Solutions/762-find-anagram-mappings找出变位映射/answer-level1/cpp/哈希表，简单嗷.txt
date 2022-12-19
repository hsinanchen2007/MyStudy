```
class Solution {
public:
    vector<int> anagramMappings(vector<int>& A, vector<int>& B) {
        vector<int> a;
        map<int,int> m;
        for(int i=0;i<B.size();i++){
            m[B[i]]=i;
        }
        for(int i=0;i<A.size();i++){
            a.push_back(m[A[i]]);
        }
          return a;
              
    }
  ;
};
```
