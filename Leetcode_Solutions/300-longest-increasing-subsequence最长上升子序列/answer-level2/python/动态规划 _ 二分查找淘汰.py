
```python []

    # 通过二分查找维护一个最长上升子序列
    # 通过循环不断淘汰，腾出位置
    def lengthOfLIS(self, nums: List[int]) -> int:
        if len(nums) == 0:
            return 0
        lis = [nums[0]]
        l = len(nums)
        for i in range(l):
            low = self.lowerBound(lis, nums[i])
            if low == len(lis):
                lis.append(nums[i])
            else:
                lis[low] = nums[i]
        
        return len(lis)
    

    # 二分查找第一个大于目标元素的元素位置
    def lowerBound(self, array: List[int], value: int) -> int:
        low = 0
        high = len(array)
        while low < high:
            mid = int((low + high) / 2)
            if value <= array[mid]:
                high = mid
            else:
                low = mid + 1
        
        return low
```
```java []
    public int lengthOfLIS(int[] nums) {
        if (nums.length == 0) return 0;
        int[] dp = new int[nums.length];

        int res = 1;
        for (int i = 0; i < nums.length; i++) {
            dp[i] = 1;
            for (int j = 0; j < i ; j++) {
                if (nums[i] > nums[j]) {
                    dp[i] = Math.max(dp[i], dp[j] + 1);
                }
            }
            if (dp[i] > res) res = dp[i];
        }
        return res;
    }
```
