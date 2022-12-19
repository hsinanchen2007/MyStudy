```cpp
class Solution {
public:
    vector<int> exchange(vector<int>& nums) {
        vector<int> result(nums);
        for (int i = 0, j = 0; j < result.size(); j++) {
            if (result[j] % 2 != 0) {
                swap(result[i], result[j]);
                i++;
            }
        }
        return result;
    }
};