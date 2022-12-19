
```cpp
class Solution {
public:
    string minNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end(), [](int a, int b){
            string astr = to_string(a);
            string bstr = to_string(b);
            return (astr+bstr).compare(bstr+astr) < 0;
        });
        
        string ans;
        int size = nums.size();
        for(int i = 0; i < size; ++i){
            ans += to_string(nums[i]);
        }
            
        return ans;
    }
};
```