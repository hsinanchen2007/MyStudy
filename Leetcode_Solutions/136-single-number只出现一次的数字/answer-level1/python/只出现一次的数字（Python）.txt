这一题我尝试了好几种方法，最开始想到的是暴力法。无非就是先用个set()函数去重，然后遍历set集合，看里面的元素在原nums集合里的个数是否为1，借助count()函数。结果是超出时间限制，代码如下：
```python
class Solution(object):
    # 可用count(num)查找列表nums中单个元素num在列表nums中的个数情况
    def singleNumber(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        set_nums = set(nums)
        for num in set_nums:
            if nums.count(num) == 1:
                return num

if __name__ == "__main__":
    nums = [2, 3, 2]
    unique_num = Solution().singleNumber(nums)
    print(unique_num)
```
既然，set集合的遍历效率较低，当时我就想到了用遍历效率最快的dict字典来遍历了。果不其然有奇效，代码如下：
```python
class Solution(object):
    # 可用count(num)查找列表nums中单个元素num在列表nums中的个数情况
    def singleNumber(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        nums_dict = {}
        for num in nums:
            nums_dict[num] = nums_dict.get(num, 0) + 1

        for key, val in nums_dict.items():
            if val == 1:
                return key

if __name__ == "__main__":
    nums = [2, 3, 2]
    unique_num = Solution().singleNumber(nums)
    print(unique_num)
```
执行效率在91%左右。

![image.png](https://pic.leetcode-cn.com/90615ec13556fb36267a46c4de17335e9203717cfc9f06a0f33aa892f5da7f84-image.png)
当时写到这儿还不满足，就想到去看看网上一些大佬的思路。真的是太受启发了，有两种方法也是真的简单，我一一列举出来。

方法三：

思路是：通过这些不重复的元素和的两倍减去原来nums的和，得到的结果就是单个元素。是不是脑洞大开？哈哈哈哈哈哈

代码如下：
```python
class Solution(object):
    # 通过这些不重复的元素和的两倍减去原来nums的和，得到的结果就是单个元素
    def singleNumber(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        set_nums = set(nums)
        return 2*sum(set_nums)-sum(nums)

if __name__ == "__main__":
    nums = [2, 3, 2]
    unique_num = Solution().singleNumber(nums)
    print(unique_num)
```
执行效率在94%左右。

![image.png](https://pic.leetcode-cn.com/afe5c788af669b1f667531de2fc927cc367806fdbc3082ce9a4236b5fe4a88f0-image.png)
方法四：

思路：可用异或运算快速找到只出现依次的数字。 两个相同的数字做异或运算结果为0；0与非0数字做异或运算结果为非零运算。

代码如下：
```python
class Solution(object):
    # 可用异或运算快速找到只出现依次的数字
    # 两个相同的数字做异或运算结果为0；0与非0数字做异或运算结果为非零运算
    def singleNumber(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        singel_num = 0
        for num in nums:
            singel_num ^= num
        return singel_num

if __name__ == "__main__":
    nums = [2, 3, 2]
    unique_num = Solution().singleNumber(nums)
    print(unique_num)
```
执行效率在97%左右。

![image.png](https://pic.leetcode-cn.com/ff3086820210046cf80a3f395475b570e14045617e7e9ee8667e3ce16ab84ad6-image.png)