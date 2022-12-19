```
class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& A) {
        int hang = A.size();
        int lie = A[0].size();
        vector<vector<int>> result; 
        for (int k = 0; k < lie; k++) {
            vector<int> element;
            for (int l = 0; l < hang; l++) {
                element.push_back(0);
            }
            result.push_back(element);
        }
        
        for (int i = 0; i < hang; i++) {
            for (int j = 0; j < lie; j++) {
                result[j][i] = A[i][j];
            }
        }
        return result;
    }
};
```
