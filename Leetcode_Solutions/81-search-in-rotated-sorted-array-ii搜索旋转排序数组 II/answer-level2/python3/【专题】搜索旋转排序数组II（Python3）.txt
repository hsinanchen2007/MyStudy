## 思路

搜索旋转数组的题目截止目前（2020-02-26）一共有三道，我之前也写过一道题解[面试题11. 旋转数组的最小数字](https://leetcode-cn.com/problems/xuan-zhuan-shu-zu-de-zui-xiao-shu-zi-lcof/solution/tu-jie-er-fen-fa-python3-by-azl397985856/) 大家也可以参考一下，对比去理解。

这道题相对而言更容易想到。 我们还是将数组分成两部分，一部分是左边有序，一部分是右边有序。

- 初始化左右指针，分别指向数组两个端点
- 我们找到中间元素，并判断中间元素在左边有序还是右边有序部分。
- 判断依据：
1. 如果nums[mid] > nums[l], 说明在左边有序
2. 如果nums[mid] < nums[l], 说明在右边有序
3. 如果nums[mid] == nums[l], 不确定在哪。 但是我们可以令 l += 1。 原因在于假如num[l] 等于target，那么 nums[mid] 也等于target，我们不会错过正确答案。 
- 如果在左边有序，并且nums[l] <= target < nums[mid]，那么我们令r = mid - 1即可。
- 后面的逻辑类似，大家看代码即可


## 关键点

- 为什么在左边有序判断nums[l] <= target < nums[mid]？在右边有序判断nums[mid] < target <= nums[r]？

因为如果mid在左边有序部分，那么我们能够确定l在左边有序部分，如果mid在右边有序部分，那么我们能确定r在右边有序部分。 That's It！

- 我们的算法是完备的，每一个都考虑到了else情况。

- 注意，循环退出的条件不再是普通的 l >= r 而是 l > r。具体可以看下面代码


## 代码

```python
class Solution:
    def search(self, nums: List[int], target: int) -> bool:
        l, r = 0, len(nums) - 1

        while l <= r:
            mid = (l + r) // 2
            if nums[mid] == target: return True
            # mid 在左边有序部分
            if nums[mid] > nums[l]:
                if nums[l] <= target < nums[mid]:
                    r = mid - 1      
                else:
                    l = mid + 1
            # mid 在右边有序部分
            elif nums[mid] < nums[l]:
                if nums[mid] < target <= nums[r]:
                    l = mid + 1
                else:
                    r = mid - 1
            # 不确定在左边有序部分还是右边有序部分
            else:
                l += 1

            
        return False
```

当然你也可以选择和nums[r]进行比较

```python
class Solution:
    def search(self, nums: List[int], target: int) -> bool:
        l, r = 0, len(nums) - 1

        while l <= r:
            mid = (l + r) // 2
            if nums[mid] == target: return True
            # mid 在左边有序部分
            if nums[mid] > nums[r]:
                if nums[l] <= target < nums[mid]:
                    r = mid - 1      
                else:
                    l = mid + 1
            # mid 在右边有序部分
            elif nums[mid] < nums[r]:
                if nums[mid] < target <= nums[r]:
                    l = mid + 1
                else:
                    r = mid - 1
            # 不确定在左边有序部分还是右边有序部分
            else:
                r -= 1

            
        return False
```



**复杂度分析**
- 时间复杂度：$O(logN)$，最坏的情况全部命中nums[mid] == nums[l]，时间复杂度退化到$O(N)$，其中N为数组长度。
- 空间复杂度：$O(1)$

欢迎关注我的公众号《脑洞前端》获取更多更新鲜的LeetCode题解

![](https://pic.leetcode-cn.com/89ef69abbf02a2957838499a96ce3fbb26830aae52e3ab90392e328c2670cddc-file_1581478989502)