### 解题思路
数据分为有序段和无序段进行二分查找

### 代码

```java []
class Solution {
    public int findMin(int[] nums) {
        // 二分法查找
        int N = nums.length;
        if(N <= 0)
            return 0;

        return binarySearch(nums, 0, N);
    }

    private int binarySearch(int []nums, int start, int end){
        int minV = Integer.MAX_VALUE;
        while(start < end){
            int mid = start + ((end-start)>>1);
            // 如果前半段有序
            if(nums[start] <= nums[mid]){
                minV = Math.min(minV, nums[start]);
                // 定位到后半段
                start = mid+1;
            }
            // 前半段无序
            else{
                minV = Math.min(minV, nums[mid]);
                // 在半段继续查找
                end = mid;
            }
        }
        return minV;
    }
}
```
```python []
class Solution:
    def findMin(self, nums: List[int]) -> int:
        N = len(nums)
        if N == 0:
            return 0
        return self.binarySearch(nums, 0, N)


    def binarySearch(self, nums, start, end):
        minV = float('inf')
        while start < end:
            mid = start + ((end-start)>>1)
            if nums[start] < nums[mid]:
                minV = min(nums[start], minV)
                start = mid+1
            else:
                minV = min(nums[mid], minV)
                end = mid

        return minV
```
```c++ []
class Solution {
public:
    int findMin(vector<int>& nums) {
        // 使用二分法进行定位, 为严格上升序列
        // 数组可以被分为有序段和无序段
        if(nums.size() <= 0)
            return -1;

        return binaryFind(nums, 0, nums.size());

    }

    int binaryFind(vector<int> &nums, int start, int end){
        int minV = INT32_MAX;
        while(start < end){
            int mid = start+((end-start)>>1);
            // 如果前半段为有序
            if(nums[start] <= nums[mid]){
                minV = min(minV, nums[start]);
                start = mid+1;
            }
            // 无序段
            else{
                minV = min(minV, nums[mid]);
                end = mid;
            }
        }
        return minV;
    }
};
```