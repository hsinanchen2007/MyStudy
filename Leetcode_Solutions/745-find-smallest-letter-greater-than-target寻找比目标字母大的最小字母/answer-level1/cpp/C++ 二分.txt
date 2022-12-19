蛋疼，letters居然不是严格递增的。。。搞到我画蛇添足。
没啥好说的，先处理了边界条件：字母是循环的。然后用二分解决。
```
class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int start = letters[0];
        if (start > target) {
            return start;
        }
        int size = letters.size();
        int end = letters[size-1];
        if (target >= end) {
            return start;
        }
        int l = 0;
        int r = size;
        while (l < r) {
            int mid = l + (r-l)/2;
            int n = letters[mid];
            if (target < n) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return letters[l];
    }
};
```