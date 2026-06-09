

```
class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
        for(auto& row:A){  // 由于需要修改row中的值，所以要用auto&而不是auto
            for(int i=0; i<(row.size()+1)/2; i++)
                if(row[i]==row[row.size()-1-i])
                    row[i]= row[row.size()-1-i] = 1 - row[i];
        }
        return A;
    }
};
```
