### 解题思路
（1）如果采用暴力算法，在每一次滑动窗口内都求一次最大值，每一次求最大值都需要遍历O(K),那么时间复杂度为O(n*k),运行时间为800ms
（2）所以在每一次滑动时，都会出现2种情况：a）最大值被滑出（概率1/k）；b）最大值未被滑出(k-1/k)
（3）a)最大值被滑出，则重新遍历求新窗口中的最大值 ; b）最大值未被滑出，只需比较最大值与将滑入的值的大小（无需遍历）
这样就减少了算法时间 时间大约是224ms

```python
class Solution:
    def maxSlidingWindow(self, nums: List[int], k: int) -> List[int]:
        if not nums: return nums
        stack=nums[:k]#定义一个滑动窗
        MAX=max(stack)
        ans=[MAX]
        for i in range(k,len(nums)):#此处注意i 的范围
            left=stack[0]#判断被滑出的数
            stack.pop(0)
            stack.append(nums[i])
            if MAX==left:
                MAX=max(stack)
            else:
                if MAX<nums[i]:
                    MAX=nums[i]
            ans.append(MAX)
        return ans
            
            


```