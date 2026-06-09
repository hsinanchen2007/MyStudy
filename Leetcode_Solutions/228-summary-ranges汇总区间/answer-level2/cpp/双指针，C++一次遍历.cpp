![image.png](https://pic.leetcode-cn.com/db81246ca850f19ba38daf639ac3fef19f40c37798a4a9a7f16652e0d9777a8d-image.png)

```
class Solution {
  public:
    vector<string> summaryRanges(vector<int> &nums) {
        vector<string> res;
        if (nums.size() == 0) {
            return res;
        }

        int left = nums[0];
        int right = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == (right + 1)) {
                right++;
                continue;
            } else {
                add(left, right, res);
                left = nums[i];
                right = nums[i];
            }
        }
        add(left, right, res);

        return res;
    }

    void add(int left, int right, vector<string> &res) {
        if (left == right) {
            res.push_back(to_string(left));
        } else {
            string tmp;
            tmp += to_string(left);
            tmp += "->";
            tmp += to_string(right);
            res.push_back(tmp);
        }
    }
};
```
