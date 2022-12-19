```
class Solution {
public:
    int twoSumLessThanK(vector<int>& A, int K) {
        sort(A.begin(), A.end());
        //排除不可能情况
        if (A.empty() || (A[0] >= K && K > 0) || A[0] > K || A.size() < 2)
        {
            return -1;
        }
        //初始记录为-1
        int limitSum = -1;
        bool firstCalculation = true;
        //记录两个变量分别从两端开始
        for (int i = A.size() - 1, j = 0; i > j;)
        {
            //剔除不存在负数情况下的一些变量
            if (A[i] >= K && A[0] >= 0)
            {
                --i;
                continue;
            }
            //大于等于目标值则需要缩小A[i]的值
            if (A[i] + A[j] >= K)
            {
                --i;
                continue;
            }
            else
            {
                if (firstCalculation)
                {
                    //第一次计算必保留结果，limitSum为最接近K的值
                    limitSum = A[i] + A[j];
                    firstCalculation = false;
                }
                else
                {
                    //后续找到比limitSum还大的值进行覆盖
                    if (A[i] + A[j] >limitSum)
                    {
                        limitSum = A[i] + A[j];
                    }
                }
                //没有超过K值因此尝试变大A[j]的值，寻找更接近的和
                ++j;
            }
        }
        //返回结果
        return limitSum;
    }
};
```
