# 解题思路

本题解决需要懂2处知识：1. 鸽巢理论；2. 异或交换
1. 具体到此处是：N个巢（数组下标），N个鸽子（数字），有至少2个鸽子在一个巢里，至少有一个鸽子没出现在巢里。
你需要找到鸽子和巢的关系：鸽子要放到鸽子数字减一的巢里，换句话说：**鸽子ID - 1 = 巢ID**

所以如果将所有鸽子整理到正确的巢，发现有的巢有2个鸽子，那么这俩鸽子就是重复的数字，
而空的巢存放着本该有的鸽子，本该有的鸽子就是消失的数字（**巢ID+1**）

2. 整理鸽子到正确的巢，需要用到异或，这样不需要额外空间
3. time：O(N)，space：O(1)

同理能找[leetcode442: 数组中重复的数据](https://leetcode-cn.com/problems/find-all-duplicates-in-an-array/submissions/)（进错巢的鸽子）


```python []
class Solution(object):
    def findDisappearedNumbers(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        def swap(nums, i1, i2):
            if i1 == i2:
                return
            nums[i1] = nums[i1] ^ nums[i2]
            nums[i2] = nums[i1] ^ nums[i2]
            nums[i1] = nums[i1] ^ nums[i2]
        
        l = len(nums)
        for i in range(l):
            while (nums[i] != nums[nums[i] - 1]):  # 每次交换至少将一个鸽子放到正确的位置，直到当前巢有正确的鸽子
                swap(nums, i, nums[i] - 1)
        
        return [ i+1 for i in range(l) if nums[i] != (i+1)]

```
```java []
class Solution {
    public void swap(int[] nums, int index1, int index2){
        if (index1 != index2){
            nums[index1] = nums[index1] ^ nums[index2];
            nums[index2] = nums[index1] ^ nums[index2];
            nums[index1] = nums[index1] ^ nums[index2];
        }
    }
    public List<Integer> findDisappearedNumbers(int[] nums) {
        int l = nums.length;
        List<Integer> ret = new ArrayList<>();
        
        for (int i = 0; i < l; i++){
            while (nums[i] != nums[nums[i]-1]){
                swap(nums, i, nums[i]-1);
            }
        }
        
        for (int i = 0; i < l; i++){
            if (nums[i] != i+1){    // 如果鸽子不在正确的巢里
                ret.add(i+1);       // 这个巢本该有的鸽子就是缺失的数字
            }
        }
        return ret;
    }
}
```