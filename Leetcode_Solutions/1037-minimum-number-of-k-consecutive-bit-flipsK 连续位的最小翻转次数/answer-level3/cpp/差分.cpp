从左到右遍历，需要翻转的情况有以下两种：
1.原数为1且翻转次数为奇数。
2.原数为0且翻转次数为偶数。
出现以上两种情况时，将[l,l+K-1]内的翻转次数加一，这可以使用差分进行优化,令diff[l]++,diff[l+K]--，复杂度O(N)。
```
class Solution {
public:
    int minKBitFlips(vector<int>& A, int K) {
        int N= A.size(),cnt = 0;
        vector<int> diff(N+5);
        for(int i = 1;i <= N; ++i){
            diff[i] += diff[i-1];
            if(A[i-1]==1 && diff[i] % 2 == 1){
                ++cnt;
                if(i+K-1 > N){
                    return -1;
                }
                diff[i]++,diff[i+K]--;
            }
            if(A[i-1] == 0 && diff[i] % 2 == 0) {
                ++cnt;
                if(i+K-1 > N){
                    return -1;
                }
                diff[i]++,diff[i+K]--;
            }
        }
        return cnt;
    }
};
```

