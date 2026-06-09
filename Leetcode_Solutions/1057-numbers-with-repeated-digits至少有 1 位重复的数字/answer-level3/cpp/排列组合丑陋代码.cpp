答案就是 N 减去 没有重复数字的个数

可运用排列组合求得

*代码挂着先*

4ms

```cpp
class Solution {
public:
    int numDupDigitsAtMostN(int N) {
        if(N <= 10) return 0;

        vector<int> v, vis(10, 0);
        // 排除1位的数字 1-9
        long long res = N-9;
        // A[i] = i! 阶乘
        vector<long long> A;
        A.push_back(1);
        for(int i = 1; i <= 10; ++i) A.push_back(A.back()*i);

        for(int tmp = N; tmp; tmp /= 10)
            v.push_back(tmp%10);
        reverse(v.begin(), v.end());
        // i表示当前数字的长度
        for(int i = 2; i < v.size(); ++i)
            // -A_10_i^A^i_i
            // 减去 有0-9十个数字 选i个
            // 加上 0开头的数字
            res += -A[10]/A[10-i]+A[9]/A[10-i];

        // 再处理位数相同的
        // 比如当前是3xxx, 那么减去1xxx, 2xxx的情况
        // 第一位
        res -= (v[0]-1)*(A[9]/A[9-v.size()+1]);
        vis[v[0]] = 1;
        for(int i = 1; i < v.size(); ++i)
        {
            // 每位每位放，确保当前数字小于N且没有重复
            for(int j = 0; j < v[i]; ++j)
                // A_(9-i)^(v.size()-i-1)
                if(!vis[j]) res -= A[9-i]/A[10-v.size()];
            // 有重复了后面的就可以不用考虑了
            if(vis[v[i]]) break;
            vis[v[i]] = 1;
            // 到了最后一位，说明N本身是没重复的
            if(i == v.size()-1) res--;
        }
        return res;
    }
};
```