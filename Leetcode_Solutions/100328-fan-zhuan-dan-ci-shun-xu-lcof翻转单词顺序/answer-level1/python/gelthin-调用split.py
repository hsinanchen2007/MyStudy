### 解题思路
同习题[151. 翻转字符串里的单词](https://leetcode-cn.com/problems/reverse-words-in-a-string/)

### 代码

```python3
class Solution:
    def reverseWords(self, s: str) -> str:
        # 如果直接调用 split 比较简单
        # 如果要自己去实现 split 的效果，需要利用延后处理的策略
        
        word_list = s.split()
        word_list = word_list[::-1]
        res = " ".join(word_list)
        return res



```