![5d683ec5516e3f3104f75fc8c06ab6e.png](https://pic.leetcode-cn.com/9efe5d563408e5058e00f4e59a6708b033b72803da34847c5335d8839578980c-5d683ec5516e3f3104f75fc8c06ab6e.png)

要原地实现移动0，只需要双指针，代码如下：
```java []
class Solution {
    public void moveZeroes(int[] nums) {
        int i = 0;  // i是第一个指针，代表第i个非零数
        for (int j = 0; j < nums.length; j++)  // j是第二个指针，代表第j个数
        {if (nums[j] != 0)  // 如果第j个数非0，那么把第j个数放到第i个位置上，并且i++
        {int temp = nums[i];
         nums[i] = nums[j];
         nums[j] = temp;
        i++;}
         }  // 完成后，最够若干位（i+1以及后面的位置）自动都交换变成0
    }
}
```
```python []
class Solution:
    def moveZeroes(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        i = 0  ## i是第一个指针，代表第i个非零数
        for j in range(len(nums)):  ## j是第二个指针，代表第j个数
            if nums[j]:  ## 如果第j个数非0，那么把第j个数放到第i个位置上，并且i += 1
                nums[i], nums[j] = nums[j], nums[i]
                i += 1
        return nums  ## 完成后，最够若干位（i+1以及后面的位置）自动都交换变成0
```
