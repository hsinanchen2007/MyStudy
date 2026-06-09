### 解题思路
  本题和[523. 连续的子数组和](https://leetcode-cn.com/problems/continuous-subarray-sum/solution/qian-zhui-he-by-jarvis1890-2/)类似（建议先做那题），都是通过判断两个位置的余数是否相等，从而判断他们的子区间的和是否为`K`的倍数。[523. 连续的子数组和]更简单一点，只要找出一个即可。
  本题将负数进行同余预处理。如给出：`[2,-2,2,-4]`，`K=6`。同余处理之后得到`[2,4,2,2]`，`K=6`，求余数之后为`[0,2,0,2,4]`,余数相等的有两对，答案是`2`.

### 其他前缀和题型
1. [560. 和为K的子数组](https://leetcode-cn.com/problems/subarray-sum-equals-k/)
2. [724. 寻找数组的中心索引](https://leetcode-cn.com/problems/find-pivot-index/)
3. [1171. 从链表中删去总和值为零的连续节点](https://leetcode-cn.com/problems/remove-zero-sum-consecutive-nodes-from-linked-list/)


### 代码

```cpp
class Solution {
public:
    int subarraysDivByK(vector<int>& A, int K) {
        unordered_map<int, int> mp; // 存余数
        mp[0] = 1;
        int ans = 0;
        int sum = 0;
        for(int i=0;i<A.size();i++){
            // 同余处理
            if(A[i] < 0) A[i] = K - abs(A[i]) % K;
            //判断是否存在这样的子区间
            sum = sum+A[i];
            int cur = sum % K;
            if(mp.count(cur)) {
                ans += mp[cur];
            }
            mp[cur]++;
        }
        return ans;
    }
};
```