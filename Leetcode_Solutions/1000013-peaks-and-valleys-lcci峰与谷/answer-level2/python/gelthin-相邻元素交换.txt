### 解题思路
参看校友大佬的解法 [O(n)时间复杂度](https://leetcode-cn.com/problems/peaks-and-valleys-lcci/solution/onshi-jian-fu-za-du-by-jerry_nju/)

这题真的很奇妙， 解答中可以强制奇数位为峰或者谷，两种都可以实现。都不知道测试样例是如何判定的。
另外对于相同的元素，既可以算是峰，也可以算是谷，无需处理。

现假设 a > b ? c ? d ? ...

经过第一次交换后，得到 b<a ? c ? d? ...
+ 若 a>c， 则有 b< a > c ? d ? ...， 无需处理 a 和 c
+ 若 a<c, 推出 b<a<c?d?..., 则交换 a,c 得到 b<c>a?d?...

到这里，前两位已经处理好，接下来处理 > c?d?... or  > a?d?... 

+ 若 c<d  或者 a < d, 则在往后一位，无需处理
+ 若 c>d 或者 a>d, 则需要交换 c d 或者 a d



### 代码

```python3
class Solution:
    def wiggleSort(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        # 可以证明峰谷交错的顺序总是可以实现的， 且同一组数，既可以 峰谷..., 也可以 谷峰...
        n = len(nums)
        if n <= 1:
            return None
        # 先要求0,2,4 为谷，1,3,5.. 为峰
        for i in range(1, n):
            if i%1 == 0 and nums[i-1] > nums[i]:  # 相同值无需处理，交不交换都一样
                nums[i-1], nums[i] = nums[i], nums[i-1]  # 交换两者的值
            if i%2 == 0 and nums[i-1] < nums[i]:
                nums[i-1], nums[i] = nums[i], nums[i-1] # 交换两者的值
        

```