首先审题，下一个最小的字典序

数据
- 1,2,3 → 1,3,2
- 3,2,1 → 1,2,3
- 1,1,5 → 1,5,1

第一个思路，从后往前找到nums[i]>nums[i-1], 交换即可，于是提交。
发现了错误
- 1,3,2 → 3,1,2 错误
- 1,3,2 → 2,1,3 正解

于是有了第二个改正版的思路， 找到nums[i]>nums[i-1], 从后面找一个比nums[i-1]大的最小值替换，再对后面的由小到大排序即可。

以为很完美了，也通过了。看题解后发现了忽略的后面数据是有序的。
因为
1. 找的过程是从后往前 nums[i]<= nums[i-1] continue, 也就是说，从i往后，全是nums[i+1]<=nums[i]，即不上升序列，如3，2，2，1
2. 找到i满足nums[i]>nums[i-1]后，从i开始找一个比nums[i-1]大的最小值设为t，即nums[t-1]>=nums[t]>nums[i-1]>=nums[t+1]
3. 交换nums[t]与nums[i-1],发现，后面部分并没有改变逆序的关系
4. 因此，直接i到数组最后一位，逆序输出，不必排序。

于是就有了最终版本，下面是代码。

改进后不需要排序代码、C++版本改进后代码、改进前的python代码

```python []
class Solution:
    def nextPermutation(self, nums: List[int]) -> None:
        def reverse(nums: List[int], left: int, right: int):
            while left<right:
                nums[left], nums[right] = nums[right], nums[left]
                left += 1
                right -= 1
        
        n = len(nums) - 1
        index = n
        while index>0 and nums[index] <= nums[index-1]:
            index -= 1
        
        if index > 0:
            for j in range(n, index-1, -1):
                if nums[j] > nums[index-1]:
                    nums[index-1], nums[j] = nums[j], nums[index-1]
                    break
            reverse(nums, index, n)
        else:
            reverse(nums, 0, n)
```
```C++ []
class Solution {
private:
    void swap(int &a, int &b) {
        int tmp = a;
        a = b;
        b = tmp;
    }
    void reverse(vector<int>& nums, int left, int right) {
        while (left<right) {
            swap(nums[left++], nums[right--]);
        }
    }
public:
    void nextPermutation(vector<int>& nums) {
        
        int n = nums.size() - 1;
        int index = n;
        while (index>0 && nums[index] <= nums[index-1])
            index--;
        
        if (index > 0) {
            for (int j=n;j>index-1;j--)
                if (nums[j] > nums[index-1]) {
                    swap(nums[index-1], nums[j]);
                    break;
                }
            reverse(nums, index, n);
        }
        else
            reverse(nums, 0, n);
    }
};
```
```python []
class Solution:
    def quicksort(self, nums: List[int], left: int, right: int) -> None:
        if left>=right:
            return
        i, j = left+1, right
        pivot = nums[left]
        while i<=j:
            while i <= j and nums[i] < pivot:
                i += 1
            while i <= j and nums[j] >= pivot:
                j -= 1
            if i<j:
                nums[i], nums[j] = nums[j], nums[i]

        nums[left], nums[j] = nums[j], nums[left]
        self.quicksort(nums, left, j-1)
        self.quicksort(nums, j+1, right)
        
    def nextPermutation(self, nums: List[int]) -> None:
        right = len(nums) - 1
        while right>0 and nums[right-1] >= nums[right]:
            right -= 1
        
        if right>0 and nums[right-1] < nums[right]:  # 能交换的
            index = right
            for i in range(right, len(nums)):    # 往右找个比当前大的最小值交换
                if nums[i] < nums[index] and nums[i] > nums[right-1]:
                    index = i
                    
            nums[right-1], nums[index] = nums[index], nums[right -1]
            self.quicksort(nums, right, len(nums) -1)
            return
        
        left = 0; right = len(nums) - 1
        while left<right:
            nums[left], nums[right] = nums[right], nums[left]
            left += 1
            right -= 1
```


