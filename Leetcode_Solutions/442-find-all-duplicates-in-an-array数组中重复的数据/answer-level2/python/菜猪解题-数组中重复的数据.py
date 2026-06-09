这一题其实是和第287题-[寻找重复数](https://zhuanlan.zhihu.com/p/118497425)比较类似的，287题中是假设只有一个重复的整数，本题中是没有规定重复数字的个数，但是有设定元素只能出现1次或者2次,。我们先来解答下此题，因为没有限制重复元素的个数，所以就不能采用第287题中的抽屉原理了。其实，我们会发现，解答给定一个整数数组 a，其中1 ≤ a[i] ≤ n （n为数组长度）这类题目时。总是会要用到一个规律或定理的，此题亦不例外，采用的原理为：
`借用索引号，我们用索引0表示数字1，索引1表示数字2...，当有个数字num，
我们将num - 1的位置的数字取相反数，连续两次取相反数会变回来，便可判断元素出现次数。`

原理知道了，代码也就能很快写出来了。

代码如下：
```Python
class Solution(object):
    def findDuplicates(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        res = []
        for val in nums:
            if nums[abs(val)-1] > 0:
                nums[abs(val) - 1] *= -1
            else:
                res.append(abs(val))
        return res


if __name__ == "__main__":
    nums = [1,3,4,2,2]
    result = Solution().findDuplicates(nums)
    print(result)
```

执行效率在70%左右，还算可以！
![image.png](https://pic.leetcode-cn.com/a8a456388f26a7dec5365ee42c19eea74345e14e5fb8ba374710c1510055dec0-image.png)

这题解决了，我们可以再来看看[第287题](https://leetcode-cn.com/problems/find-the-duplicate-number/)，将本题的思想应用到上面去，发现也能解决。

代码如下：
```Python
class Solution(object):
    def findDuplicate(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        res = []
        for val in nums:
            if nums[abs(val)-1] > 0:
                nums[abs(val) - 1] *= -1
            else:
                res.append(abs(val))
        return res[0]


if __name__ == "__main__":
    nums = [3, 1, 3, 4, 2]
    duplicate_num = Solution().findDuplicate(nums)
    print(duplicate_num)
```

注意，此处规定了重复数字只有一个，所以取第一个元素。本以为很开心的又找到了一个方法，看了下第287题的要求，才发现要求1中说明了：不能更改原数组（假设数组是只读的）。害，白高兴一场，大家就当找个乐吧哈哈哈哈。

