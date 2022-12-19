### 解题思路
分析：子串+去重
方法一：
遍历算法，暴力算法
略去……

方法二：
还是遍历，只不过大踏步地遍历
类似滑动窗口协议
遍历string，如果找到新元素，就添加到curSub子串中，如果找到旧元素，直接在curSub中删去该元素上一个位置以前的序列，形成新的子串

方法三：
尝试利用桶排序，未完成

### 代码

```python3
class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        curSub=[0]
        #maxSub=[]
        curSubLen=0
        maxSubLen=0
        for everyChar in s:
            if everyChar in curSub:
                curSub.append(everyChar)
                curSub=curSub[curSub.index(everyChar)+1:]
                curSubLen=len(curSub)
            else:
                curSub.append(everyChar)
                curSubLen+=1
            maxSubLen=curSubLen if curSubLen>maxSubLen else maxSubLen
            '''
            if curSubLen>maxSubLen:
                maxSubLen=curSubLen
                maxSub=curSub
            '''
        return maxSubLen
```