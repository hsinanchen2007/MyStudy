```cpp


// [2, 6, 1, 8] will get wrong index in c1, c2 , but it won't destroy its logic. 
//Cause when c1 = 1, this is beacuse there is 2 < 6 before.
class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        if (nums.size() < 3) return false;
        int c1 = INT_MAX, c2 = INT_MAX;
        for (int c: nums) {
            if (c <= c1) c1 = c;
            else if (c <= c2) c2 = c;
            else 
                return true;
        }
        return false;
    }
};
```