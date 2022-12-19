只需要保存两个状态变量即可：
1，保持该位置的数字不变，截止到现在的最优解
2，交换该位置的两个数字，截止到现在的最优解
```
class Solution {
public:
    int minSwap(vector<int>& A, vector<int>& B) {
        int N = A.size();
        if (N < 2) return 0;        
        int res_keep = 0; // 保持该位置的数字不变
        int res_swap = 1; // 交换该位置的两个数字
        for (int i = 1; i < N; ++i) {
            bool b1 = (A[i] > A[i - 1] && B[i] > B[i - 1]);
            bool b2 = (A[i] > B[i - 1] && B[i] > A[i - 1]);
            if (b1 && b2) {
                res_keep = min(res_keep, res_swap);
                res_swap = 1 + res_keep;
            } else if (b1) {
                res_swap = res_swap + 1;
            } else if (b2) {
                int t = res_swap;
                res_swap = res_keep + 1;
                res_keep = t;
            }
        }
        return min(res_swap, res_keep);
    }
};
```
![image.png](https://pic.leetcode-cn.com/0ec71605255b859eb892ac101b34e80f0d481fde218b0d141373cd7cf1f8080f-image.png)
