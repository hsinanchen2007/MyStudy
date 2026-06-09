1. 该题目没有做出来，没有太多的思路；
2. 后来看了解法，用排列组合的合适来求解，实际为数学问题，确实没有解出来;
3. |arr1[i] - arr1[j]| + |arr2[i] - arr2[j]| + |i - j|最终在这几个范围中选择最大值
```
    arr1[i] - arr1[j] + arr2[j] - arr2[i] + i-j (i > j)
    arr1[i] - arr1[j] + arr2[i] - arr2[j] + i-j (i > j)
    arr1[j] - arr1[i] + arr2[j] - arr2[i] + i-j (i > j)
    arr1[j] - arr1[i] + arr2[i] - arr2[j] + i-j (i > j)
    arr1[i] - arr1[j] + arr2[j] - arr2[i] + j-i (i < j)
    arr1[i] - arr1[j] + arr2[i] - arr2[j] + j-i (i < j)
    arr1[j] - arr1[i] + arr2[j] - arr2[i] + j-i (i < j)
    arr1[j] - arr1[i] + arr2[i] - arr2[j] + j-i (i < j)
```
```
class Solution {
public:
    int maxAbsValExpr(vector<int>& arr1, vector<int>& arr2) {
        int n = arr1.size();
        int res = 0;
        vector<int> dp1(n,0);
        vector<int> dp2(n,0);
        vector<int> dp3(n,0);
        vector<int> dp4(n,0);
        /*
        arr1[i] * arr1[j] + arr2[i] * arr2[j] + i * j;
        */
        for(int i = 0;i < n; ++i){
            dp1[i] = arr1[i] + arr2[i] - i;
            dp2[i] = arr1[i] + arr2[i] + i;
            dp3[i] = arr1[i] - arr2[i] + i;
            dp4[i] = arr2[i] - arr1[i] + i;
        }
        sort(dp1.begin(),dp1.end());
        sort(dp2.begin(),dp2.end());
        sort(dp3.begin(),dp3.end());
        sort(dp4.begin(),dp4.end());
        res = max(res,dp1[n-1]-dp1[0]);
        res = max(res,dp2[n-1]-dp2[0]);
        res = max(res,dp3[n-1]-dp3[0]);
        res = max(res,dp4[n-1]-dp4[0]);
        return res;
    }
};
```