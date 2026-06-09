```
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& arr) {
        int n = arr.size();
        int m = arr[0].size();
        pair<int, int> last_min1 = make_pair(0, -1);
        pair<int, int> last_min2 = make_pair(0, -1);
        for(int i = 0; i < n; ++i)
        {
            pair<int, int> curr_min1 = make_pair(INT_MAX, -1);
            pair<int, int> curr_min2 = make_pair(INT_MAX, -1);
            for(int j = 0; j < m; ++j)
            {

                if(get<1>(last_min1) != j)
                {
                    arr[i][j] = get<0>(last_min1) + arr[i][j];
                }
                else
                {
                    arr[i][j] = get<0>(last_min2) + arr[i][j];
                }
                if(arr[i][j] < get<0>(curr_min1))
                {
                    get<0>(curr_min2) = get<0>(curr_min1);
                    get<1>(curr_min2) = get<1>(curr_min1);
                    get<0>(curr_min1) = arr[i][j];
                    get<1>(curr_min1) = j;
                }
                else if(arr[i][j] < get<0>(curr_min2))
                {
                    get<0>(curr_min2) = arr[i][j];
                    get<1>(curr_min2) = j;
                }
            }
            last_min1 = curr_min1;
            last_min2 = curr_min2;
        }
        int min_val = INT_MAX;
        for(auto i : arr[n-1])
        {
            if(i < min_val)
            {
                min_val = i;
            }
        }
        return min_val;
    }
};
```
