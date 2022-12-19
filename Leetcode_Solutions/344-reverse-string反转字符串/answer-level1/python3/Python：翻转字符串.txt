### 解题思路
我觉得Python翻转啥都好像没啥实际意义，通过步长和reverse函数肯定是O(n)的空间，即使是双指针，从算法上讲，应该是O(1)了，但是在实际运行过程中，每次都消耗不同的内存，一次循环下来，还是O(n)啊，这个不知道具体Python底层是怎么处理的，如果有大佬，希望不吝赐教！

### 代码

```python3
class Solution:
    def reverseString(self, s: List[str]) -> None:
        """
        Do not return anything, modify s in-place instead.
        """
        #s[:]=s[::-1]
        #s.reverse()
        l,r=0,len(s)-1
        while r-l>0:
            s[l],s[r]=s[r],s[l]
            l+=1
            r-=1
```