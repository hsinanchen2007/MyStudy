### 解题思路
时间复杂度O(n)
空间复杂度O(1)
使用一个字典记录第一次出现的某个状态，当后续有该状态出现时，中间的子字符串即满足条件。
变量名的冗余，代码的冗余，有助于更好地理解代码，帮助你更快，没有bug地A出答案。
还没A出来，就精简代码，很不划算。

### 代码

```python3

### 代码

```python3
class Solution:
    def findTheLongestSubstring(self, s: str) -> int:
        cache,max_,nums,num={'a':0,'e':0,'i':0,'o':0,'u':0},0,{(0,0,0,0,0):-1},(0,0,0,0,0)
        for i,j in enumerate(s):
            if j in cache:
                cache[j]=(cache[j]+1)%2
                num=tuple(cache.values())
                if num not in nums:
                    nums[num]=i
            max_=max(i-nums[num],max_)
        return max_
```
补充下状态压缩版本的代码
```
class Solution:
    def findTheLongestSubstring(self, s: str) -> int:
        cache,max_,nums,num={'a':0,'e':1,'i':2,'o':3,'u':4},0,{0:-1},0
        for i,j in enumerate(s):
            if j in cache:
                num=num^(1<<cache[j])
                if num not in nums:
                    nums[num]=i
            max_=max(i-nums[num],max_)
        return max_
```
