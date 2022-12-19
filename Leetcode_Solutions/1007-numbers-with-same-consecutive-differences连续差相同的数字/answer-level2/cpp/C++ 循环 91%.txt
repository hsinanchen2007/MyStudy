执行用时 :8 ms, 在所有 cpp 提交中击败了91.61%的用户
内存消耗 :9.7 MB, 在所有 cpp 提交中击败了81.03%的用户
```
class Solution {
public:
    vector<int> numsSameConsecDiff(int N, int K) {
        //N=1边界情况
        if(N == 1) return {0,1,2,3,4,5,6,7,8,9};
        vector<int> pre, res;
        //根据条件生生成第一个数字
        for(int i = 1; i <= 9; ++i){
            if(i >= K || (i + K <= 9)){
                pre.push_back(i);
            }
        }
        for(int i = 1; i < N; ++i){
            res.erase(res.begin(), res.end());
            for(int n : pre){
                if(n % 10 + K <= 9){
                    res.push_back(n * 10 + n % 10 + K);
                }
                //避免K=0时重复生产
                if(n % 10 - K >= 0 && K != 0){
                    res.push_back(n * 10 + n % 10 - K);
                }
            }
            pre = res;
        }
        return res;
    }
};
```
