### 解题思路
首先这道题最原始的思路可以是深搜，那么很容易想到加上剪枝，那么这样的时间复杂度仍然很高。
对于这道题本质上还是排序问题，我们可以想想能否使用排序方法作为基础，我们就以快排作为框架，那么需要改动的地方就是如何定义两个字符串的顺序：如果str1 + str2 < str2 + str1那么我们就将str1放在str2前面即可。

性能优化：如果对所有的n个数字进行快排，那么时间复杂度是O(nlogn)的，但是我们考虑一个问题，假如给定两个最高位不同的字符串，比如"123"和"34"，我们可以通过最高位大小直接判断"123"应该在"34"前面，基于这种思想我们可以对上面的快排进行性能优化：首先根据最高位对nums中的数字进行分组，即分成0-9共十组，那么这十个组中数字的绝对顺序就已经确定了在后面的组中的数字肯定要出现在前面的组中的数字的后面，然后我们再对每个组中的数字进行快排，当nums中的数字较多且分布较均匀时，该方法对性能的提升是非常显著的。

### 代码

```python
class Solution(object):
    def minNumber(self, nums):
        """
        :type nums: List[int]
        :rtype: str
        """
        if nums == []:
            return ''
        num_list = [[] for _ in range(10)] # 记录开头数字为i的数字
        num_len_list = [0] * 10 # 记录开头数字为i的数字中最大的长度
        # 按照第一个数字进行分类
        for i in range(len(nums)):
            num = str(nums[i])
            head_num = int(num[0])
            num_list[head_num].append(num)
            if len(num) > num_len_list[head_num]:
                num_len_list[head_num] = len(num)
        # print(num_list)
        # print(num_len_list)
        # print('*' * 50)
        # 定义快排
        def quick_sort(data, left, right):
            if right - left < 1:
                return 
            p = left
            q = right
            temp = data[left]
            while p < q:
                while p < q and temp + data[q] < data[q] + temp:
                    q -= 1
                if p < q:
                    data[p] = data[q]
                    p += 1
                while p < q and data[p] + temp < temp + data[p]:
                    p += 1
                if p < q:
                    data[q] = data[p]
                    q -= 1
            data[p] = temp
            quick_sort(data, left, p - 1)
            quick_sort(data, p + 1, right)
        res = ''
        # 重排数字并生成答案
        for i in range(10):
            if num_list[i] == []:
                continue
            quick_sort(num_list[i], 0, len(num_list[i]) - 1)
            # print(num_list[i])
            for num in num_list[i]:
                # print(num)
                res += num

        return res
```