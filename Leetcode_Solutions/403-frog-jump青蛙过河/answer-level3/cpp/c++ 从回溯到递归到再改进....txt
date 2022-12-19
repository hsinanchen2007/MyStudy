### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
    const int SIZE = 1101;
public:
    // 回溯法会超时
    bool dfs(const set<int> &ss, int cur, int k, int target){
        if(cur == target) return true;
        if(cur > target) return false;
        for(int i = 1; i >= -1; i--){
            int next = cur + k + i;
            if(next > cur && ss.find(next) != ss.end()){
                if(dfs(ss, next, k+i, target)) return true;
            }
        }
        return false;
    }

    bool _canCross(vector<int>& stones) {
        if(stones.size() <= 1) return true;
        if(stones[1] != 1) return false;
        set<int> ss;
        for(const int &val: stones) ss.insert(val);
        return dfs(ss, 1, 1, stones[stones.size()-1]);
    }

    // 后向dp还是超时。。。
    // 时间复杂度为O(N*1100),线性级别，为啥还超时呢
    bool __canCross(vector<int>& stones) {
        int N = stones.size();
        if(stones[1] != 1) return false;
        map<int,int> hash;  // stone_index -> vec_index;
        for(int i = 0; i < N; i++) hash[stones[i]] = i;
        vector<vector<int>> dp(N, vector<int>());
        dp[1].push_back(1);
        for(int i = 1; i < N; i++){
            for(const int &k: dp[i]){
                if(k-1 > 0 && hash.find(stones[i]+(k-1)) != hash.end()) dp[hash[stones[i]+(k-1)]].push_back(k-1);
                if(k > 0 && hash.find(stones[i]+k) != hash.end()) dp[hash[stones[i]+k]].push_back(k);
                if(hash.find(stones[i]+k+1) != hash.end()) dp[hash[stones[i]+k+1]].push_back(k+1);
            }
        }
        return !dp[N-1].empty();
    }

    // dp算法   ---WTF,还是超时。。。
    // 步长最大为1100，因此每次最多比上次增1个
    // dp[i][k]表示位置i能否在上一跳通过跳k个距离达到
    bool ___canCross(vector<int>& stones) {
        int N = stones.size();
        if(stones[1] != 1) return false;  // 特殊情况处理
        map<int,int> hash;  // stone_index -> vec_index;
        for(int i = 0; i < N; i++) hash[stones[i]] = i;
        vector<vector<bool>> dp(N, vector<bool>(SIZE, false));
        dp[1][1] = true;
        for(int i = 2; i < N; i++){
            for(int k = 1; k < SIZE; k++){
                int pre = stones[i]-k;
                if(pre < 0) continue;
                if(hash.find(pre) != hash.end()){
                    int pre_index = hash[pre];
                    dp[i][k] = (k > 1 && dp[pre_index][k-1]) || dp[pre_index][k] || dp[pre_index][k+1];
                    //dp[i][k] |= dp[pre_index][k];
                    //dp[i][k] |= dp[pre_index][k+1];
                }
            }
        }
        for(int k = 1; k < SIZE; k++){
            if(dp[N-1][k]) return true;
        }
        return false;
    }

    // dp算法 --改进
    // 继承上一步的dp算法，我们之所以超时，可能是因为在遍历步长k的时候进行了过多的无用的遍历
    // 因此我们只考虑石头间的间隙作为可能的步长
    bool canCross(vector<int>& stones) {
        int N = stones.size();
        if(stones[1] != 1) return false;  // 特殊情况处理
        map<int,int> hash;  // stone_index -> vec_index;
        for(int i = 0; i < N; i++) hash[stones[i]] = i;
        vector<vector<bool>> dp(N, vector<bool>(SIZE, false));
        dp[1][1] = true;
        for(int i = 2; i < N; i++){
            for(int j = 0; j < i; j++){
                int k = stones[i] - stones[j];
                if(k < SIZE){
                    dp[i][k] = dp[j][k-1] || dp[j][k] || dp[j][k+1];
                }
            }
        }
        for(int k = 1; k < SIZE; k++){
            if(dp[N-1][k]) return true;
        }
        return false;
    }
};
```