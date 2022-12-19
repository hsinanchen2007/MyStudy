### 解题思路
方法1. 滑动窗口
相当于一个队列，如果满足要求，就不断进入队列，当某个元素进入队列导致不满足要求时，就移动队列。
依次移出队列左边的元素，直到满足要求
移动窗口，一直维持满足要求的队列，直到字符串尾，输出最长队列。
方法2. 双指针
设置左右两个指针:left_index,right_index
右指针不断向前移动，并判断当前位置的元素是否出现过
若出现过：更新左边指针位置到重复元素位置的下一位
继续移动右指针，更新最大长度

### 代码

```python3
class Solution:
    '''
    def lengthOfLongestSubstring(self, s: str) -> int:
        if s == None: return 0
        left_index = 0
        substring = set()
        max_length = 0
        current_length = 0
        for i in range(len(s)):
            current_length += 1
            while s[i] in substring:
                substring.remove(s[left_index])
                left_index += 1
                current_length -= 1
            if current_length > max_length:
                max_length = current_length
            substring.add(s[i])
        return max_length
    '''
    def lengthOfLongestSubstring(self, s: str) -> int:
        if len(s)==0 or len(s)==1 :
            return len(s)
        left_index = 0
        right_index = 0
        current_length = 0
        max_length = 0
        for i in range(len(s)):
            # 如果出现重复元素
            if s[right_index] in s[left_index:right_index]:
                repeated_index = (s[left_index:right_index]).index(s[right_index])
                left_index = left_index + repeated_index + 1 # 左指针移动到重复元素后的一个位置 
            right_index += 1 # 右指针右移一位
            current_length = right_index - left_index
            if current_length > max_length:
                max_length = current_length
        return max_length
```