### 解题思路
啦啦啦，目前共做了4个，第一个没有参考大佬答案的自己做出来的中等题，完全是按照像人类一样看见一个字符串如何找无重复最长子串的方法进行实现的。在自己做题的过程中，发现代码针对不同的测试用例，开始没有考虑完全，总是在修修补补，提交很多次才通过最终的测试。

思路：
1. 首先第一遍遍历确定子串的起点
2. 设置长度n=1，然后遍历该点后面的字符，如果在前面没有出现过，则n加1，如果出现过，则输出当前的n；并跳出循环，看下一个起点
3. 在确定无重复子串终点时，要判断该点是否为整个字符串的重点，如果是，则输出当前的长度，但不需要跳出循环，因为本身就已结束内部循环，然后看下一个起点
4. 排序输出最长的无重复子串长度。

### 代码

```python3
class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        length = []
        if len(s)<2 :
            length.append(len(s))
        for i in range(len(s)-1):
            n = 1
            for j in range(i+1,len(s)):
                if s[j] not in s[i:j]:
                    n = n+1
                    if j == len(s)-1:
                        length.append(n)
                else:
                    length.append(n)
                    break
        print(length)
        
        length.sort()
        return length[-1]

                

```