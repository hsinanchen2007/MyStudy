### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def longestOnes(self, A: List[int], K: int) -> int:
        n=len(A)
        if K>=n:
            return n
        #双指针
        left=0
        right=0

        count=0#统计0的个数
        ans=0 #保存结果
        while right<n:
            if A[right]==0:
                count+=1
            # 滑动窗口  保证k个0 
            while count>K:
                if A[left]==0:
                    count-=1
                left+=1
            ans=max(ans,right-left+1)
            right+=1
        return ans
```