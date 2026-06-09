### 解题思路
假设dp[i][0/1]表示从A[i]开始，先进行 偶跳跃/奇跳跃 ，能否到达终点，则状态转移方程为：

- dp[i][0] = dp[A[i]通过偶跳跃到达的下一个索引j(j>i)][1]
- dp[i][1] = dp[A[i]通过奇跳跃到达的下一个索引j(j>i)][0]

则最后要求的答案为：dp[i][1]=1的起始点i的个数

因此，现在要解决的问题就是：如何求A[i]通过 偶跳跃/奇跳跃 后到达的下一个索引j

观察发现，从后往前遍历A[i]，A[i]下一步会跳到的地方只与已经遍历过的A[i+1,...]的值以及当前是奇跳跃还是偶跳跃有关：

- 奇跳跃：跳到略大于A[i]的(大于A[i]的数里最小的)、索引最小的值
- 偶跳跃：跳到略小于A[i]的(小于A[i]的数里最大的)、索引最小的值

为了达到O(nlogn)的时间复杂度，需要上述的每一次跳跃步骤在O(logn)内完成，因而想到了用可排序的set，插入和查找都是O(logn)


### 代码

```cpp
class Solution {
public:
    int oddEvenJumps(vector<int>& A) {
        int size = A.size();
        if(size == 1) return 1;
        vector<vector<bool>> dp(size, vector<bool>(2, false));
        dp[size-1][0] = true;//从终点开始无奇偶跳跃都为true
        dp[size-1][1] = true;
        set<pair<int, int>> idxs;//升序存储已经遍历过的<A[i], i>数据对
        idxs.insert(make_pair(A[size-1], size-1));
        int ans = 1;
        for(int i = size-2; i >= 0; i--){//从后向前遍历
            auto it = idxs.upper_bound(make_pair(A[i], i));//返回的指针严格大于搜索值
            if(it == idxs.end()){//无法进行奇跳跃
                //偶跳跃
                it--;
                int next = it->first;//遍历过的略小于A[i]的数，即小于A[i]的数里最大的那个
                //要一直找到值为该数的索引最小的那个数
                while(it != idxs.begin() && it->first == next)
                    it--;
                if(it != idxs.begin() || (it == idxs.begin() && it->first != next))
                    it++;
                dp[i][0] = dp[it->second][1];
            }
            else if(it->first > A[i]){//可以奇跳跃到更大的数
                dp[i][1] = dp[it->second][0];//当前所指就是遍历过的略大于A[i]的数里索引最小的
                if(it != idxs.begin()){//可以进行偶跳跃到更小的数
                    it--;
                    int next = it->first;
                    while(it != idxs.begin() && it->first == next)
                        it--;
                    if(it != idxs.begin() || (it == idxs.begin() && it->first != next)){
                            it++;
                    }
                    dp[i][0] = dp[it->second][1];
                }
            }
            else{//遍历过的数里有和A[i]相等的，奇偶跳跃都会到该数上
                dp[i][0] = dp[it->second][1];
                dp[i][1] = dp[it->second][0];
            }
            if(dp[i][1]) ans++;
            idxs.insert(make_pair(A[i], i));
        }
        return ans;
    }
};
```