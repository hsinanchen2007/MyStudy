### 解题思路
线性法, 时间复杂度$O(N)$
二分法, 时间复杂度$O(lg N)$

### 代码

**线性法**
```c++ []
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        // 线性搜索法, 时间复杂度O(N)
        // 二分搜索定位峰值, 时间复杂度O(lg N)
        int N = nums.size();
        if(N <= 1)
            return 0;

        int i=1;
        while(i<N-1){
            if(nums[i-1] < nums[i] && nums[i]>nums[i+1]){
                return i;
            }
            ++i;
        }
        if(nums[0] > nums[1])
            return 0;
        else
            return N-1;
    }
};
```
**二分法**
```java []
class Solution {
    public int findPeakElement(int[] nums) {
        int N = nums.length;
        if(N <= 1)
            return 0;
        // 二分法定位峰值
        return getPeakValue(nums, 0, N-1);
    }

    private int getPeakValue(int []nums, int start, int end){
        // 使用区间
        while(start+1 < end){
            int mid = start+(end-start)/2;
            if(nums[mid-1] < nums[mid] && nums[mid] > nums[mid+1])
                return mid;
            // 在上升区间
            else if(nums[mid-1] < nums[mid])
                start = mid;
            // 在下降区间
            else 
                end = mid;
        }
        if(nums[0] > nums[1])
            return 0;
        else
            return end;
    }
}
```
```python []
class Solution:
    def findPeakElement(self, nums: List[int]) -> int:
        N = len(nums)
        if N == 1:
            return 0
        return self.getPeakValue(nums, 0, N-1)

    def getPeakValue(self, nums, start, end):
        # 区间查询
        while start+1 < end:
            mid = start + (end-start)//2
            if nums[mid-1]<nums[mid] and nums[mid]>nums[mid+1]:
                return mid
            # 上升阶段
            elif nums[mid-1]<nums[mid]:
                start = mid
            # 下降阶段
            else:
                end = mid

        if nums[0] > nums[1]:
            return 0
        else:
            return end
```
```c++ []
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        // 二分法
        int N = nums.size();
        if(N == 1)
            return 0;
        
        int start = 0, end = N-1;
        // 区间查询
        while(start+1 < end){
            int mid = start + (end-start)/2;
            // mid为顶点
            if(nums[mid-1]<nums[mid] && nums[mid]>nums[mid+1])
                return mid;
            // 如果mid处于上升趋势
            if(nums[mid-1] < nums[mid])
                start = mid;
            // 如果mid处于下降趋势
            else
                end = mid;
        }
        if(nums[0]>nums[1])
            return 0;
        return N-1;
    }
};
```
