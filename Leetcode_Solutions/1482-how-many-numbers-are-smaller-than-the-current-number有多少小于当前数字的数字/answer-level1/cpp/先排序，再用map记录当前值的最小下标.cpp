
```
class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        int length = nums.size();
        vector<int> answer(length, 0);
        vector<int> temp = nums;
        unordered_map<int, int> index;
        sort(temp.begin(), temp.end());
        for (int i = length - 1; i >= 0; --i) {
            index[temp[i]] = i;
        }
        for (int i = 0; i < length; ++i) {
            answer[i] = index[nums[i]];
        }
        return answer;
    }
};
```

