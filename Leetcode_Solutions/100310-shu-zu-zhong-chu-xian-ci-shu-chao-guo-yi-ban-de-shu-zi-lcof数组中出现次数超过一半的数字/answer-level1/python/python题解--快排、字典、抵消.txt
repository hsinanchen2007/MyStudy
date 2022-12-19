### 1.直接排序
![image.png](https://pic.leetcode-cn.com/4f5aec9fcab71124f1c5d7f85462cc7fe5c79b9db7490a4d0d464301e2eea03f-image.png)

- 直接将数组排序,取中间元素
- 由于`sort()`函数使用的是`Timsort`方法,一种归并方法的改进
- 时间复杂度为`O(nlogn)`
```
class Solution(object):
    def majorityElement(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        if not nums:
            return None
        nums.sort()
        return nums[len(nums) / 2]

```


### 2.基于快速排序的方法
- 基于快排的方法,就是要找到当前这一回合进行完快排后的数组下标`i`是否等于数组长度的一半,如果是就直接返回结果了
- 我写了代码,但超过了时间限制,仅供参考
- 这种思路的时间复杂度为`O(n)`,空间复杂度为`O(1)`

```
class Solution(object):
    def majorityElement(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        if not nums:
            return None
        start = 0
        end = len(nums) - 1
        length = len(nums) // 2
        index = self.quickSort(nums, start, end)
        while index != length:
            if index > length:
                end = index -1
                index = self.quickSort(nums, start, end)
            else:
                start = index + 1
                index = self.quickSort(nums, start, end)
        return nums[index]

    def quickSort(self, arr, start, end):
        low = start
        high = end
        temp = arr[low]
        while low < high:
            while low < high and arr[high] > temp:
                high -= 1
            arr[low] = arr[high]
            while low < high and arr[low] < temp:
                low += 1
            arr[high] = arr[low]
        
        arr[low] = temp
        return low

```


### 3.使用字典进行搜索
![image.png](https://pic.leetcode-cn.com/667a63cf12b51761e301421218772fe1d2e0948f1d02caf61073531579573cbe-image.png)


- 我们使用字典这种数据结,也就是哈希表来进行查找.
- 开始遍历整个数组,如果当前数字没有在字典中,就把它加入进去,如果在字典中,则把它的数量加 1 ,接着判断下它的数量是否是大雨整个数组的一半,如果是的话,则直接返回当前数值,否则,继续遍历.
- 由于字典的查找时间复杂度为`O(1)`,所以总的时间复杂度为`O(n)`,空间复杂度为`O(n)`
```
class Solution(object):
    def majorityElement(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        if not nums:
            return None
        if len(nums) == 1:
            return nums[0]
        write = {}
        for i in nums:
            if i not in write:
                write[i] = 1
            else:
                write[i] += 1
                if write[i] > (len(nums) / 2):
                    return i
        return None



```

###4.根据数组特性找出答案---抵消法
![image.png](https://pic.leetcode-cn.com/b7fb6f1101eefb906d85c687a219228a43bb49f14a151368de74e675fe6b15e7-image.png)

- 数组中有一个数字出现的次数超过了数组长度的一半,也就是说他出现的次数比其它所有数字出现的次数要多
- 因此我们可以考虑在遍历数组的时候保存两个值`result`和`times`,其中`result`用来保存数组中的数字,`times`用来保存次数
- 当我们遍历到下一个数字的时候,如果先一个数字和我们之前保存的数字相同那么`times += 1`,如果不相同那么`tiems -= 1`.
- 当`times == 0`时我们就需要重新记录下一个数字了
- 那么最后经过相互的抵消,`result`中就是超过一半的那个数字,因为别的数字全部被抵消掉了
- 时间复杂度`O(n)`,空间复杂度`O(1)`

### 代码

```python
class Solution(object):
    def majorityElement(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        if not nums:
            return None
        result = nums[0]
        times = 1
        for i in nums[1:]:
            if times == 0:
                result = i
                times = 1
            elif i == result:
                times += 1
            else:
                times -= 1
        return result

```
