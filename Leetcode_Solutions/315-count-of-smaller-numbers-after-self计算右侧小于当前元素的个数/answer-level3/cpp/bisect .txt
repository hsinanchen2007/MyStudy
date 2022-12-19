```cpp
class Solution {
private:
    // self define lower_bound, we can use stl lower_bound as below or comment code in self define function
    int lower_bound_(int num, vector<int>& order) {
        if (order.empty()) return 0;
        int l = 0, r = order.size();
        while (l < r) {
            int mid = l + (r - l) / 2;
            if (order[mid] >= num) r = mid;
            else
                l = mid + 1;
        }
        return l;
    }
public:
    vector<int> countSmaller(vector<int>& nums) {
        if (nums.empty()) return {};
        int n = nums.size();
        vector<int> count(n, 0);
        vector<int> order;
        int index;
        for (int i = n - 1; i >= 0; i --) {
            //self define lower bound, also AC
            // index = lower_bound_(nums[i], order);
            // order.insert(order.begin()+index, nums[i]);
            auto it = std::lower_bound(order.begin(), order.end(), nums[i]);
            index = it - order.begin();
            count[i] = index;
            order.insert(it, nums[i]);
        }
        return count;
    }
};

```