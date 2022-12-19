```
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> cur(rowIndex + 1, 1);
        for(int k = 0; k <= rowIndex; k++){
            for(int j = k - 1; j > 0; j--){
                cur[j] = cur[j - 1] + cur[j];
            }
        }
        return cur;
    }
};
```
