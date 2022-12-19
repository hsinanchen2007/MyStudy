```
class Solution {
public:
    int maxArea(vector<int>& height) {
        int N = height.size();
        int res = 0;
        int left = height[0];
        int right = height[N - 1];
        res = (N - 1) * min(left, right);
        int l = 0;
        int r = N - 1;
        while (l < r) {
            if (left > right) {
                while (l < r && height[--r] <= right);
                if (l >= r) break;
                right = height[r];
                res = max(res, (r - l) * min(left, right));
            } else {
                while (l < r && height[++l] <= left);
                if (l >= r) break;
                left = height[l];
                res = max(res, (r - l) * min(left, right));
            }
        }
        return res;
    }
};
```
![image.png](https://pic.leetcode-cn.com/0ac73c0398eb06b6435a7cdbd63eccdd00636f0a0a1a01a23c273e403fb7ab24-image.png)
