```cpp
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        for (int i = 0; i < numbers.size(); ++i) {
            int other = search(numbers, target - numbers[i]);
            if (other != -1) {
                if (other < i) return {other + 1, i + 1};
                return {i + 1, other + 1};
            }
        }
        return {};
    }

    // 
    int search(vector<int>& numbers, int target) {
        int lo = 0, hi = numbers.size() - 1;
        while (lo < hi) {
            int mid = lo + (hi - lo + 1 >> 1);
            if (target >= numbers[mid]) {
                lo = mid;
            } else {
                hi = mid - 1;
            }
        }
        return numbers.empty() ? -1 : (target == numbers[lo] ? lo : -1);
    }
};
```
