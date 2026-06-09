```C++ []
class ZigzagIterator {
public:
    vector<int> indices;
    vector<vector<int> > nums;
    int k;
    int r;
    ZigzagIterator(vector<int>& v1, vector<int>& v2) {
        indices = {0, 0};
        nums = {v1, v2};
        k = 2;
        r = 0;
    }

    int next() {
        if (hasNext()) {
            int res = nums[r][indices[r]];
            ++indices[r];
            ++r;
            return res;
        }
        return -1;
    }

    bool hasNext() {
        for (int i = 0; i < nums.size(); ++i) {
            r = (r + i) % k;
            if (indices[r] < nums[r].size()) {
                return true;
            }
        }
        return false;
    }
};
```

![image.png](https://pic.leetcode-cn.com/1a12630c7be956f4502b9de0879854a8896a45620251d8ad0794a21866c48ae2-image.png)
