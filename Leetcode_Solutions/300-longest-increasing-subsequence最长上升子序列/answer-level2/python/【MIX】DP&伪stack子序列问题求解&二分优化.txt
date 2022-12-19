### 解题思路
$dp[i]$表示以nums[i]为结尾的最长上升子序列, 时间复杂度$O(N^2)$, 如果配合二分查找时间复杂度可以降为$O(NlgN)$

**动态规划**
### 代码
```java []
class Solution {
    public int lengthOfLIS(int[] nums) {
        int N = nums.length;
        if(N <= 0)
            return 0;
        if(N == 1)
            return 1;
        // 定义dp[i]表示以nums[i]为结尾的最长上升子串
        int[] dp = new int[N];
        for(int i=0; i<N; ++i)
            dp[i] = 1;
        
        int max_dp = dp[0];
        for(int i=1; i<N; ++i){
            for(int j=0; j<i; ++j){
                if(nums[j]<nums[i] && dp[i]<dp[j]+1)
                    dp[i] = dp[j]+1;
            }
            if(dp[i]>max_dp)
                max_dp = dp[i];
        }
        return max_dp;
    }
}
```
```python []
class Solution:
    def lengthOfLIS(self, nums: List[int]) -> int:
        N = len(nums)
        if N <= 0:
            return 0
        elif N==1:
            return 1
        dp = [1 for _ in range(N)]
        for i in range(1, N):
            for j in range(0, i):
                if nums[j]<nums[i] and dp[i]<dp[j]+1:
                    dp[i] = dp[j]+1
        return max(dp)
```
```c++ []
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        // 设计状态转移方程
        // 令dp[i]表示以nums[i]为结尾的最长子序列的长度
        int n = nums.size();
        if(n == 0)
            return 0;
        else if(n == 1)
            return 1;
        vector<int> dp(n, 1);
        int max_seq = 1;
        for(int i=1; i<n; ++i){
            
            for(int j=0; j<i; ++j){
                if(nums[i]>nums[j])
                    if(dp[i] < dp[j]+1)
                        dp[i] = dp[j]+1;
            }
            cout<<dp[i];
            // 更新
            if(dp[i] > max_seq)
                max_seq = dp[i];
        }
        return max_seq;
    }
};
```
**伪stack**
### 代码
```java []
class Solution {
    public int lengthOfLIS(int[] nums) {
        // 使用伪栈 + 贪心
        if(nums.length <= 0)
            return 0;
        ArrayList<Integer> arr = new ArrayList<>();
        arr.add(nums[0]);
        for(int i=1; i<nums.length; ++i)
            if(nums[i] > arr.get(arr.size()-1))
                arr.add(nums[i]);
            else{
                for(int j=0; j<arr.size(); ++j)
                    if(nums[i] <= arr.get(j)){
                        arr.set(j, nums[i]);
                        break; 
                    }
            }

        return arr.size();
    }
}
```
```python []
class Solution:
    def lengthOfLIS(self, nums: List[int]) -> int:
        # 使用伪栈+贪心算法
        if len(nums) <= 0:
            return 0
        
        st = []
        st.append(nums[0])
        for i in range(1, len(nums)):
            if nums[i] > st[-1]:
                st.append(nums[i])
            else:
                for j in range(len(st)):
                    if nums[i] <= st[j]:
                        st[j] = nums[i]
                        break
        return len(st)
```
```c++ []
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        // 方法2：使用stack配合贪心算法
        if(nums.size()<=0)
            return 0;
        vector<int> stack;
        // stack[i]表示长度为i+1的上升子序列最后一个元素的最小可能取值
        stack.push_back(nums[0]);
        for(int i=1; i<nums.size(); ++i){
            if(nums[i] > stack.back())
                stack.push_back(nums[i]);
            else{
                for(int j=0; j<stack.size(); ++j){
                    if(nums[i]<=stack[j]){
                        stack[j] = nums[i];
                        break;
                    }
                }
            }
        }
        return stack.size();
    }
};
```
**二分法优化**
### 代码
```java []
class Solution {
    public int lengthOfLIS(int[] A) {
        int N = A.length;
        // b[i]存储最小的A[x], 当f[x]=i
        int []b = new int[N+1];
        int top= 0;
        b[0] = Integer.MIN_VALUE;
        int i, j = 0, start, stop, mid;

        for(i=0; i<N; ++i){
            start = 0;
            stop = top;
            while(start <= stop){
                mid = start + ((stop-start)>>1);
                if(b[mid] < A[i]){
                    j = mid;
                    start = mid+1;
                }
                else{
                    stop = mid-1;
                }
            }
            b[j+1] = A[i];
            if(j + 1> top)
                top = j+1;
        }

        return top;
    }
}
```
```python []
class Solution:
    def lengthOfLIS(self, nums: List[int]) -> int:
        N = len(nums)
        b = [0 for _ in range(N)]
        res = 0
        for num in nums:
            start, end = 0, res
            while start < end:
                mid = start + ((end-start)>>1);
                if b[mid] < num:
                    start = mid+1
                else:
                    end = mid

            b[start] = num
            if end == res:
                res += 1
        return res
```
```c++ []
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        // 算法优化, 将时间复杂度优化到O(NlgN)
        // 分析:
        // 状态: f[i] 以第i个字符为结尾的最长上升子序列的长度
        // 方程: f[i] = max(f[i], f[j]+1 | a[j]<a[i])
        // 对于f值: 1, 2... 记录当前为止拥有这个f值最小的a[i]
        // 优化思想:
        // 对于一个新进入的数a[j], 计算f值为f[i]+1, 其中a[i]<a[j], 且a[i]为最小, f[j] = f[i]+1
        // 使用二分查找优化, 在序列a[i], a[2], a[5]...中找打最后一个比它小的数a[i], f[j]为f[i]+1
        // * 序列是一致单调增的 --> 二分法优化
        // * 序列长度<=N, LIS长度<=N

        int N = nums.size();
        // b存储当f[x]=i时, 最小的A[x], b中元素满足单调递增的性质
        vector<int> b = vector<int>(N, 0);
        int res = 0;
        for(auto num: nums){
            int start = 0, end = res;
            // 二分法 定位b中小于num的最大元素
            while(start < end){
                int mid = start + ((end-start)>>1);
                if(b[mid] < num)
                    start = mid+1;
                else
                    end = mid;
            }
            // 如果b中存在该元素, 进行更新, 不存在则进行插入
            b[start] = num;
            // 更新b数组的长度
            if(res == end)
                res++;
        }
        return res;
    }
};
```