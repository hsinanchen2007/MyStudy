```cpp
class Solution {
public:
    vector<vector<int>>* rects;
    vector<int> data{ 0 };
    Solution(vector<vector<int>>& rects) {
        this->rects = &rects;
        for (vector<int>& vec : rects)
            data.push_back(data.back() + (vec[3] - vec[1] + 1) * (vec[2] - vec[0] + 1));
    }

    vector<int> pick() {
        int r = rand() % data.back();
        int start = 1;
        int end = data.size() - 1;
        while (start < end) {
            int mid = start + (end - start >> 1);
            if (data[mid] <= r)
                start = mid + 1;
            else
                end = mid;
        }
        vector<int>& vec = (*rects)[start - 1];
        return{ vec[0] + (r - data[start - 1]) % (vec[2] - vec[0] + 1), vec[1] + (r - data[start - 1]) / (vec[2] - vec[0] + 1) };
    }
};
```
