### 解题思路
1. 双指针滑动窗口, 时间复杂度$O(N)$, 空间复杂度$O(1)$
2. 二分法, 时间复杂度$O(NlgN)$
### 代码

**双指针**
```java []
class Solution {
    public int minSubArrayLen(int s, int[] nums) {
        // 暴力算法求解, 时间复杂度O(N^3)
        // 滑动窗口求解, 时间复杂度O(N), 空间复杂度O(1)
        if(nums.length<=0)
            return 0;
        int l_index = 0;
        int r_index = -1;
        int sum = 0;
        int res = Integer.MAX_VALUE;
        while(l_index < nums.length){
            // 当前sum不满足条件
            if(r_index < nums.length-1 && sum < s){
                sum += nums[++r_index];
            }
            // 当sum>=s 或者r_index已经到达最右侧时, 只要移动l_index
            else{
                sum -= nums[l_index];
                l_index++;
            }
            // 调整后检测是否满足需求
            if(sum >= s){
                res = Math.min(res, r_index-l_index+1);
            }
            
        }
        if(res == Integer.MAX_VALUE)
            return 0;
        return res;
    }
}
```
```python []
class Solution:
    def minSubArrayLen(self, s: int, nums: List[int]) -> int:
        l = -1
        arr_sum = 0
        res = float('inf')
        for r in range(len(nums)):
            arr_sum += nums[r]
            while arr_sum >= s:
                l+=1
                arr_sum-=nums[l]
                res = min(res, r-l+1)
        return 0 if res==float('inf') else res
```

```c++ []
class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        // 连续子数组问题, 考虑使用使用滑动窗口求解
        // 时间复杂度O(N), 空间复杂度O(1)
        int l=0, r=-1;
        int sum = 0;
        int res = nums.size()+1;
        while(l<nums.size()){
            // 考虑边界条件, 移动right指针
            if(r+1<nums.size() && sum < s){
                sum += nums[++r];
            }
            // 移动left指针
            else{
                sum -= nums[l++];
            }

            if(sum >= s){
                res = min(res, r-l+1);
            }
        }
        // 检查无解的情况
        if(res == nums.size()+1)
            return 0;
        return res;
    }
};
```
```c++ []
class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        // 双指针
        int N = nums.size();
        if(N == 0)
            return 0;
        int pFast = 0;
        int pSlow = 0;
        int sum = nums[pFast];
        int L = N+1;
        while(pSlow < N && pFast<N){
            if(sum < s){
                if(pFast+1<N){
                    pFast++;
                    sum += nums[pFast];
                }
                else{
                    break;
                }
            }
            else{
                L = min(pFast-pSlow+1, L);
                sum -=nums[pSlow];
                pSlow++;
            }
        }
        if(L == N+1)
            return 0;
        return L;
    }
};
```
**二分法**
```c++ []
class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        // 二分法
        int N = nums.size();
        if(N == 0)
            return 0;
        // 建立前缀和数组, 为升序序列, 在该序列中进行二分查找
        vector<int> S(N+1, 0);
        S[0] = nums[0];
        for(int i=1; i<=N; ++i)
            S[i] = S[i-1]+nums[i-1];

        /*
        设二分法中找到S[k] >= s+S[i-1]  ==> S[k]-S[i-1] >= s
        即 nums[i-1]+nums[i]+...+nums[k-1] >= s
        序列长度为(k-1)-(i-1)+1=k-i+1, 其中k = bnd-S.begin() if bnd != S.end();
        */
        int res = INT32_MAX;
        for(int i=1; i<=N; ++i){
            int findS = s+S[i-1];
            auto bnd = lower_bound(S.begin(), S.end(), findS);
            if(bnd != S.end()) res = min(res, static_cast<int>(bnd-S.begin()-i+1));
        }
        if(res != INT32_MAX)
            return res;
        return 0;
    }
};
```
```python []
class Solution:
    def minSubArrayLen(self, s: int, nums: List[int]) -> int:
        from bisect import bisect_left

        N = len(nums)
        if N == 0:
            return 0

        S = [0 for _ in range(N+1)]
        S[0] = 0
        for i in range(1, N+1):
            S[i] = S[i-1]+nums[i-1]

        res = float('inf')
        for i in range(1, N+1):
            findS = S[i-1]+s
            k = bisect_left(S, findS)
            if k != N+1: res = min(res, k-i+1)
        if res == float('inf'): return 0
        return res
```
