```
//monotonic queue
class Solution {
private:
    struct node
    {
        int val;
        int idx;
        node(int v, int i) :val(v), idx(i) {};
    };
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ret;
        deque<node> st;
        for (int i = 0;i<nums.size();i++)
        {
            while (st.size() && st.front().idx <= i - k)
                st.pop_front();
            while (st.size() && st.back().val < nums[i])
                st.pop_back();
            if ((!st.empty() && nums[i] <= st.back().val) ||
                st.empty())
                st.emplace_back(node(nums[i], i));
            if (i >= k - 1)
                ret.emplace_back(st.front().val);
        }
        return ret;
    }
};
```
