class Solution {
public:
    int minArray(vector<int>& numbers) {
        sort(numbers.begin(),numbers.end());
        return numbers[0];

    }
};