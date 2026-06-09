找到所有可能的区间，减去不合法的区间就是答案
```
class Solution {
public:
    int numSubarrayBoundedMax(vector<int>& A, int L, int R) {
        A.push_back(R + 1);
        int edge = 0; // 每个大于R的数都可以把数组切断，找到这样的位置
        int left = 0; // 每个数都小于L的连续片段是不合法的，找到这样的区间起始点
        int all = 0; // 数组被大于R的数切断后剩余的区间个数
        int bad = 0; // 每个数都小于L的区间个数
        for (int i = 0; i < A.size(); ++i) {
            if (A[i] > R) {
                int d1 = i - edge;
                all += d1 * (d1 + 1) / 2;
                edge = i + 1;
                int d2 = i - left;
                bad += d2 * (d2 + 1) / 2;
                left = i + 1;
            } else if (A[i] >= L) {
                int d = i - left;
                bad += d * (d + 1) / 2;
                left = i + 1;
            }
        }
        return all - bad;
    }
};
```

![image.png](https://pic.leetcode-cn.com/774662897cc642138b4fe7e3972b8e658a09fff98058a4ab6c92cc7d0342960d-image.png)
