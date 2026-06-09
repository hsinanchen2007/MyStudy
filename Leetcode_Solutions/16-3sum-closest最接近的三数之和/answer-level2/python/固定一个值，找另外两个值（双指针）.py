## 思路：

数组是已排好序，首先确定一个数，在左右指针运动过程中，记录与 `target` 绝对值差值最小的。


## 代码：

```Python []
class Solution:
    def threeSumClosest(self, nums: List[int], target: int) -> int:
        
        nums.sort()
        #print(nums)
        n = len(nums)
        res = float("inf")
        for i in range(n):
            if i > 0 and nums[i] == nums[i-1]:
                continue
            left = i + 1
            right = n - 1
            while left < right :
                #print(left,right)
                cur = nums[i] + nums[left] + nums[right]
                if cur == target:return target
                if abs(res-target) > abs(cur-target):
                    res = cur
                if cur > target:
                    right -= 1
                elif cur < target:
                    left += 1
        return res
            
```

```Java []
class Solution {
    public int threeSumClosest(int[] nums, int target) {
        Arrays.sort(nums);
        //int res = Integer.MAX_VALUE;
        int n = nums.length;
        int res = nums[0] + nums[1] + nums[n-1];
        for (int i = 0; i < n - 2; i++) {
            if (i > 0 && nums[i] == nums[i-1]) continue;
            int left = i + 1;
            int right = n - 1;
            while (left < right) {
                int cur = nums[i] + nums[left] + nums[right];
                if (cur == target) return target;
                if (Math.abs(res - target) > Math.abs(cur - target)) res = cur;
                if (cur > target) right -= 1;
                if (cur < target) left += 1;
            }
        }
        return res;
        
    }
}
```
```C++ []
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        // c++ 排序
        sort(nums.begin(),nums.end());
        int res = nums[0] + nums[1] + nums[2];
        for (int i = 0; i < n - 2; i++){
            if (i > 0 && nums[i] == nums[i-1]) continue;
            int left = i + 1;
            int right = n - 1;
            while (left < right){
                int cur = nums[i] + nums[left] + nums[right];
                if (cur == target) return target;
                if (abs(res - target) > abs(cur - target)) res = cur;
                if (cur > target) right -= 1;
                if (cur < target) left += 1;
            }
        }
        
        return res;
    }
};
```

