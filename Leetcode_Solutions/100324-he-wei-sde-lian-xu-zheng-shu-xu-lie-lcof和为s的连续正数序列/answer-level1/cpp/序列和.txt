### 解题思路
- 求和为target的所有有序序列a,a+1,a+2,...a+k (其中a > 0,k >=1)
- 序列和公式： a(k+1) + k(k+1)/2
- 只需知道a和k就能确定一个序列
- k递增，求a是否符合要求。当 k(k+1)/2 >= target时，退出循环
- a > 0 且 target - k(k+1)/2 能被 k+1 整除
### 代码
```cpp
class Solution {
public:
    vector<vector<int>> findContinuousSequence(int target) {
        if(target <= 1) return {};
        vector<vector<int>> ans;
        int k = 1;
        int n = target - 1;
        while(n > 0){
            n = target - k*(k+1)/2;
            k++;
            int a = n/k; 
            if(n % k != 0 || a == 0){
                continue;
            }
            vector<int> t(k);
            iota(t.begin(),t.end(),a);
            ans.emplace_back(std::move(t));
        }
        vector<vector<int>> res;
        copy(ans.rbegin(),ans.rend(),back_inserter(res));
        return res;
    }
};
```