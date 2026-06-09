```
class Solution {
public:
    int numSubarraysWithSum(vector<int>& A, int S) {
        if (S == 0) {
            int t = 0;
            int res = 0;
            for (auto x : A) {
                if (x == 0) {
                    ++t;
                } else {
                    res += t * (t + 1) / 2;
                    t = 0;
                }
            }
            res += t * (t + 1) / 2;
            return res;
        }
        int N = A.size();
        int res = 0;
        int left = 0;
        int t = 0;
        for (int i = 0; i < N; ++i) {
            t += A[i];
            while (left <= i && t - A[left] >= S) t -= A[left++];
            if (t == S && A[i] == 1) {
                int front = left;
                int tail = i;
                while (front - 1 >= 0 && A[front - 1] == 0) --front;
                while (tail + 1 < N && A[tail + 1] == 0) ++tail;
                res += (left - front + 1) * (tail - i + 1);
            }
        }
        return res;
    }
};
```
![image.png](https://pic.leetcode-cn.com/8d90334a4d05c461295af8b5f7967b6b3d3ea75e5c1b26e79beef72cd5ee198c-image.png)
