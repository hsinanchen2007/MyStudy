```cpp
class Solution {
public:
    int countNegative(vector<int>& V){
        int l = 0, r = V.size();
        while (l < r){
            int m = l + ((r-l)>>1);
            if (V[m]>=0)
                l = m+1;
            else
                r = m;
        }
        //return l;
        return V.size() - l;
    }
    int countNegatives(vector<vector<int>>& grid) {
        int n = grid.size();
        int sum = 0;
        for (int i=0; i<n; i++){
            //cout << countNegative(grid[i]) << ' ';
            sum += countNegative(grid[i]);
        }
        return sum;
    }
};
```