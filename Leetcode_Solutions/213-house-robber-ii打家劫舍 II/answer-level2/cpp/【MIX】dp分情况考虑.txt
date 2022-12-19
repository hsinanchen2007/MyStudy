### 解题思路
对House 0和House n-1进行分情况考虑转为House Rob I问题

### 代码

```java []
class Solution {
    public int rob(int[] nums) {
        // 分情况考虑
        // 1. 不偷House 0  
        // 2. 不偷House n-1
        // 转化为 House Rob I 处理
        int N = nums.length;
        if(N == 0)
            return 0;
        if(N == 1)
            return nums[0];

        // case I: 不偷House 0
        int []f = new int[N];
        f[0] = 0;
        f[1] = nums[1];
        for(int i=2; i<N; ++i){
            f[i] = Math.max(f[i-1], f[i-2]+nums[i]);
        }

        int maxRes = f[N-1];

        // case II: 不偷House N-1
        f[0] = nums[0];
        f[1] = Math.max(nums[0], nums[1]);
        for(int i=2; i<N-1; ++i){
            f[i] = Math.max(f[i-1], f[i-2]+nums[i]);
        }
        maxRes = Math.max(maxRes, f[N-2]);
        return maxRes;        
    }
}
```
```python []
class Solution:
    def rob(self, nums: List[int]) -> int:
        N = len(nums)
        if N == 0:
            return 0
        if N == 1:
            return nums[0]

        # case I
        f = [0 for _ in range(N)]

        f[0] = 0
        f[1] = nums[1]
        for i in range(2, N):
            f[i] = max(f[i-2]+nums[i], f[i-1])
        maxRes = f[N-1]

        # case II
        f[0] = nums[0]
        f[1] = max(nums[0], nums[1])
        for i in range(2, N-1):
            f[i] = max(f[i-2]+nums[i], f[i-1])
        
        return max(maxRes, f[N-2])
```
```c++ []
class Solution {
public:
    int rob(vector<int>& nums) {
        int N = nums.size();
        if(N == 0)
            return 0;
        if(N == 1)
            return nums[0];

        auto f = vector<int>(N, 0);
        // case I
        f[0] = 0;
        f[1] = nums[1];

        for(int i=2; i<N; ++i)
            f[i] = max(f[i-1], f[i-2]+nums[i]);

        int maxRes = f[N-1];

        // case II
        f[0] = nums[0];
        f[1] = max(nums[0], nums[1]);
        
        for(int i=2; i<N-1; ++i)
            f[i] = max(f[i-1], f[i-2]+nums[i]);

        return max(maxRes, f[N-2]);
    }
};
```