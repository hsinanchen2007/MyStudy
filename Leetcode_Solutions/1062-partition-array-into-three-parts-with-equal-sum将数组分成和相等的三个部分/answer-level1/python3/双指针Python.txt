### 解题思路
利用Python解答该题目时，一般有两种思路：1.遍历整个list，一边遍历，一边累加，如果出现了一个average结果，将当前的累加和置零，结果次数加一次，接着继续累加，最后统计得到average的次数；2.利用双指针操作，分别从前后开始遍历，在这个过程中可能会遇到类似[1,-1,1,-1]的测试样例无法通过的情况，这是由于初始化的值和average相等，指针没有移动，为了解决这个问题可以考虑先做加法再去做判断，如果首位两端有一端已经和average相等，就把该节点固定住，同时节点值置零。

### 代码

```python3
class Solution:
    def canThreePartsEqualSum(self, A: List[int]) -> bool:
        l = len(A)  
        s = sum(A)
        if s % 3 != 0 :
            return False
        ave = s // 3
        left = 0  
        right = l - 1
        left_sum, right_sum = 0, 0
        res = False


        while left < right - 1:
            left_sum += A[left]
            right_sum += A[right]
            if left_sum != ave:
                left += 1
            else:
                left = left
                A[left] = 0

            if right_sum != ave:
                right -= 1
            else:
                right = right
                A[right] = 0
            if left_sum == ave and right_sum == ave:
                res = True
                break
            
        return res
```