### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& A, int K) {
        /*
        第k个最小的分数-》小于某个小数 a 的分数个数为k个
        1、二分a ~(0,1) 上下边界right 和 left；a = left +(right -left)/2
        2、寻找小于a的分数个数cnt
        如果cnt>k, 说明分数大了，缩小分数值，right左移
        如果cnt<k， 说明分数小了，增大分数值，left右移
        */
        double left = 0, right = 1.0, mid;//二分法三个指针
        int p = 0, q = 1, Asize = A.size(), cnt; // p q 分子和分母
        while (true) {
            double mid = (left + right) / 2.0;
            cnt = 0; p = 0;
            //A[i]为分子，A[j]为分母，寻找比mid小的分数个数
            for (int i = 0, j = i+1; i < Asize; ++i) {
                while (j < Asize && A[i] > mid * A[j]) {
                    ++j;// j越大 A[i]/A[j]越小
                }
                cnt += Asize - j;//以A[i]为分子，小于等于mid的分数个数
                if (j < Asize && p * A[j] < q * A[i]) {
                    p = A[i];
                    q = A[j];
                }
            }
            if (cnt == K) {//当前mid正好是所寻找的结果
                return {p, q};
            }
            else if (cnt < K) {//mid小了，所以右移left
                left = mid;
            }
            else {//mid大了，所以左移right
                right = mid;
            }
        }
        
    }
};
```