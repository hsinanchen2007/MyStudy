```
class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        register int n = nums.size(), right = -100001, rleft = -100001, rright = 100001;
        int index[n] = {0}, leftheap[n];
        auto f = [&nums, &index](int l, int r)->bool{ return nums[l][index[l]] > nums[r][index[r]]; };
        for (int i=0; i<n; i++) {
            leftheap[i] = i;
            right = max(right, nums[i][0]);
        }
        make_heap(leftheap, leftheap + n, f);
        while (true) {
            register int minarr = leftheap[0];
            register int left = nums[minarr][index[minarr]];
            if (right-left < rright-rleft) {
                rleft = left;
                rright = right;
            }
            if (++index[minarr] >= nums[minarr].size()) break;
            pop_heap(leftheap, leftheap + n, f);
            push_heap(leftheap, leftheap + n, f);
            right = max(right, nums[minarr][index[minarr]]);
        }
        return {rleft, rright};
    }
};
```
