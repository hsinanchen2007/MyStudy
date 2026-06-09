### 解题思路
参考官方题解，这一题学到了两个双指针的技巧。

官方题解 1 的解法与另一题 [删除*排序*数组中的重复项](https://leetcode-cn.com/problems/remove-duplicates-from-sorted-array/solution/shan-chu-pai-xu-shu-zu-zhong-de-zhong-fu-xiang-by-/) 几乎一模一样。 题解 1 维持了处理后的数组的相对序，可以用于处理已经排好序的数组


参考官方题解的法2，
双指针 i=0， j=n, 若 nums[i] == val, 则替换 nums[i], nums[j] = nums[j], nums[i], 此时i 不变， j -= 1, 并判断一下新替换来的值是不是仍是 val； 若 nums[i] != val， 则 i += 1

循环不变式： nums[:i+1] 表示所有不是 val 的值，而 num[j:] 表示所有为 val 的值

实现技巧:
1. j 初始化为字符串的长度 n
2. 为了节省空间，j 可以直接用变量 n 取代
3. nums[j] = nums[i] 这一步实际上可以不做，根据 “你不需要考虑数组中超出新长度后面的元素”。



### 代码

```python3
class Solution:
    def removeElement(self, nums: List[int], val: int) -> int:
        n = len(nums)
        i = 0
        while i<n:
            if nums[i] == val:
                n -= 1
                nums[i] = nums[n]
            else:
                i += 1
        return i





```