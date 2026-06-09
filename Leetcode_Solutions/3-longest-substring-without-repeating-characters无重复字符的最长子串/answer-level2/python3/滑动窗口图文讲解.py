> 思路讲解-**滑动窗口**

假设原始字符串**S**如下

![image](https://pic.leetcode-cn.com/5e6a469831d44b21d3937442d99f36f8d978c153900ee36c1c6d7443c41b1d95)

从左侧开始遍历**S**，以`i`标记窗口左侧，`j`标记窗口右侧，初始时，`i=0`，`j=0`，即开头**a**所在的位置，此时，窗口大小为**1**

然后，将`j`右移，逐步扩大窗口，依次经过**b**、**c**、**d**，此时，窗口内均无重复字符，继续右移`j`

![image](https://pic.leetcode-cn.com/6575f34473677c105dffc42a1f230b595c3ac655d4c814582e727a08920d3758)

当`j`移动到`d`后面的`a`所在位置时，对应字符`a`在窗口中**已存在**，此时，窗口大小为5，去除当前重复的一位，窗口大小为**4**。此时窗口内的字符串`abcd`为

![image](https://pic.leetcode-cn.com/ff57274ee622baefedb96786aeb4b7e1eeae70161a2ec114297dd2b7313b211f)

找到窗口中已存在的该字符所在位置，并将`i`移动到该位置下一位

![image](https://pic.leetcode-cn.com/bdf1e39068ce1f39d11d76e426600da9b86517cf6cba36812802e5c6db9f0e02)

此时为第二个窗口

![image](https://pic.leetcode-cn.com/16bf7acb8a8687fdae8396380d9c635f48e02ef2483e99afc60acc0a7b610d72)

继续重复之前的操作，直到`j`移动到字符串最后一位停止。

---

> 示例代码

```python
class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        # 如果字符串s为空，返回0
        if not s:return 0
        # 保存窗口内字符串
        lookup = list()
        n = len(s)
        # 最大子串长度
        max_len = 0
        # 当前窗口长度
        cur_len = 0
        # 遍历字符串s
        for i in range(n):
            val = s[i]
            # 如果该值不在窗口中
            if not val in lookup:
                # 添加到窗口内
                lookup.append(val)
                # 当前长度+1
                cur_len+=1
            # 如果该值在窗口中已存在
            else:
                # 获取其在窗口中的位置
                index = lookup.index(val)
                # 移除该位置及之前的字符，相当于上图中的图3到图4
                lookup = lookup[index+1:]
                lookup.append(val)
                # 当前长度更新为窗口长度
                cur_len = len(lookup)
            # 如果当前长度大于最大长度，更新最大长度值
            if cur_len > max_len:max_len = cur_len
        # 返回最大子串长度
        return max_len
```