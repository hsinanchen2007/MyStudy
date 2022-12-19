先从小到大排序，从最小的数开始替换

```
class Solution {
public:
    int largestSumAfterKNegations(vector<int>& A, int k) {
        sort(A.begin(), A.end());//递增排序
        int i = 0;
        for (i = 0; i < k; ++i) {
            if (A[i] < 0) A[i] = -A[i]; //一直变换直到A[i]为正数
            else break;
        }
        if (i < k) { //是否还需要变换
            if (A[i] != 0) { //如果A[i] == 0就不用算了
                if ((k-i) % 2) { //剩余变换的次数为奇数，还需要变换，偶数就不需要变换，因为变来变去没有改变
                    if (i < 1) A[i]   = -A[i];  //i < 1不能和i - 1做比较
                    else {
                        if (A[i] > A[i-1]) A[i-1] = -A[i-1];  //选择其中最小的数进行变换
                        else               A[i]   = -A[i];
                    }
                }
            }
        }
        int sum = 0;
        for (vector<int>::iterator it = A.begin(); it != A.end(); it++) {
            sum += *it;
        }
        return sum;
    }
};
```
