```
class Solution {
public:
    // 从右往左找到第一个可向左移动的数
    int locate(vector<int>& v) {
        int res = -1;
        for (int i = v.size() - 1; i >= 1; --i) {
            if (v[i] == 1 && v[i - 1] == 0) {
                return i;
            }
        }
        return -1;
    }
    // 将某个位置之后的1都移动到数据的最右边
    void refresh(vector<int>& v, int start_pos) {
        int left = start_pos;
        int right = v.size() - 1;
        while (left < right) {
            while (left < right && v[left] == 0) {
                ++left;
            }
            while (left < right && v[right] == 1) {
                --right;
            }
            if (left < right) {
                swap(v[left], v[right]);
            }
        }
    }
    bool forward(vector<int>& v) {
        int k = locate(v);
        if (k == -1)
            return false;
        swap(v[k - 1], v[k]);
        refresh(v, k + 1);
        return true;
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        vector<int> v(n, 0);
        vector<int> nums;
        for (int i = 0; i < k; ++i) {
            v[i + n - k] = 1;
            nums.push_back(i + n - k + 1);
        }
        res.push_back(nums);
        while (forward(v)) {
            nums.clear();
            for (int i = 0; i < v.size(); ++i) {
                if (v[i] == 1) {
                    nums.push_back(i + 1);
                }
            }
            res.push_back(nums);
        }
        return res;
    }
};
```
![image.png](https://pic.leetcode-cn.com/5e873cdec1964d8c0a0003a916d2e514c8948c21cce127b3e7a507f5f05ca262-image.png)
