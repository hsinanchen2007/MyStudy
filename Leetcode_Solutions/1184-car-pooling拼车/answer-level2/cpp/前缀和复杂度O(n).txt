前端和只要从起点到终点，车上人数总小于capacity则满足
```
class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        bool result = true;
        long long int temp[1005] = {0};
        for(int i = 0; i < trips.size(); i++){
            temp[trips[i][1]] += trips[i][0];
            temp[trips[i][2]] -= trips[i][0];
        }
        for(int i = 1; i <= 1000; i++){
            temp[i] = temp[i-1] + temp[i];
            if(temp[i] > capacity){
                result = false;
                return result;
            }
        }
        return result;
    }
};
```
