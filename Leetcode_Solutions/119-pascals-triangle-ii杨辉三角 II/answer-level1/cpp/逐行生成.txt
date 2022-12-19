```
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> v2;
        vector<int> v1;
        for(int i=0; i<=rowIndex; i++)
        {
            v1.push_back(0);
            v1[0] = 1;
            v1[i] = 1;
            for(int j=1; j<=i-1; j++)
            {
                v1[j] = v2[j-1] + v2[j];
            }
            v2 = v1;
        }
        return v1;
    }
};
```
