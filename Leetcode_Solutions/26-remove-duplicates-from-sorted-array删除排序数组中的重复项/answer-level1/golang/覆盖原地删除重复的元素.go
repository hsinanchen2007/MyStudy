### 解题思路
参考官方题解，这道题是原地删除重复数组的问题，这种问题的一般思路就是使用两个指针i,j，通过覆盖掉重复元素的方式实现原地删除
i指针记录要覆盖的索引，j指针向前探索下一个与i位置不相等的索引，逻辑如下：
（1）nums[i]==nums[j],则j++，i位置不变
（2）nums[i]!=nums[j],则i++,nums[i]==nums[j],实现覆盖

### 代码

```golang
func removeDuplicates(nums []int) int {
    i:=0
    for j:=1;j<len(nums);j++{
        if nums[j]!=nums[i]{
            i++
            nums[i]=nums[j]
        }
    }
    return i+1
}
```