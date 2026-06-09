```
class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        for(int i = 0, n = nums.size(); i < n; i++) {
            nums[i] += 50000;
        }
        vector<int> data[2][10];
        for(auto v : nums) {
            data[0][v%10].push_back(v);
        }
        int pre = 1, now = 0;
        for(int i = 1, d = 8, div = 10; i <= d; i++, div *= 10) {
            swap(pre, now);
            for(int j = 0; j < 10; j++) {
                data[now][j].resize(0);
            }
            for(int j = 0; j < 10; j++) {
                for(auto v : data[pre][j]) {
                    data[now][v/div%10].push_back(v);
                }
            }
        }
        int top = 0;
        for(int i = 0; i < 10; i++) {
            for(auto v : data[now][i]) {
                nums[top++] = v - 50000;
            }
        }
        return nums;
    }
};

```
