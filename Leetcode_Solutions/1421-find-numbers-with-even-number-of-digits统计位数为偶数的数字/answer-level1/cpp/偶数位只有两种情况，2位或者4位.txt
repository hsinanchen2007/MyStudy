class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int res = 0;
        for (auto num : nums) {
            if (num >= 10 && num <= 99) res++;
            else if (num >= 1000 && num <= 9999) res++;
        }
        return res;
    }
};