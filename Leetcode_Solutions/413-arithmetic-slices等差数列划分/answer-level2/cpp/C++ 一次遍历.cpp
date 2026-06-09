```
class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        int left = 0;
        int d = 0;
        int res = 0;
        for (int i = 1; i < A.size(); ++i) {
            if (A[i] - A[i - 1] == d) {
                res += max(i - left - 1, 0);
            } else {
                left = i - 1;
                d = A[i] - A[i - 1];
            }
        }
        return res;
    }
};
```

![image.png](https://pic.leetcode-cn.com/00fb8b1c9a343f1362871573f52209c27ae96168c3762281b4025d67741c3f5a-image.png)
