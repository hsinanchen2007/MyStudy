```
class Solution {
public:
    vector<int> anagramMappings(vector<int>& A, vector<int>& B) {

        map<int,int> mapA;
        int iter = 0;
        for(auto a:A)
            mapA[iter++] = a;
        
        map<int,int> mapB;
        iter = 0;
        for(auto b:B)
            mapB[b] = iter++;

        vector<int> index_A;
        map<int,int>::iterator A_iter =mapA.begin();
        map<int,int>::iterator B_iter;

        for(int i = 0;i<mapA.size();i++)
        {
            B_iter = mapB.find(A_iter->second);
            if(B_iter!= mapB.end())
            {
                index_A.emplace_back(B_iter->second);
            }
            A_iter++;
        }
        return index_A;
    }
};
```
