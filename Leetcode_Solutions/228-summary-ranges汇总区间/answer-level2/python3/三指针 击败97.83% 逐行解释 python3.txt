# 题解
## 三指针
 1. 特判，若数组长度为1，返回$str(nums[0])$
 2. 初始化左右指针$l=0,r=0$和当前访问指针$cur=0$。初始化结果$res=[]$
 3. 循环条件$cur<n$：
 	+ 循环条件，若$cur<n\ and\ nums[cur]-nums[r]<=1$，说明当前元素和右界可以合并，更新右界$r=cur$并将$cur=cur+1$。
 	+ 否则，说明不可以合并，则将当前的左右界加入$res$。两种情况：
 		* 若$l==r$，说明只有一个元素，加入$str(nums[l])$
 		* 否则，加入$[str(nums[l])+"->"+str(nums[r])]$
 	+ 令$l=cur,r=cur$
 
 4. 返回$res$

### 复杂度分析
 - 时间复杂度：$O\left(n\right)$，进行了一次遍历。
 - 空间复杂度：$O(1)$

### Python

```python
    def summaryRanges(self, nums: List[int]) -> List[str]:
        n=len(nums)
        if(n==1):
            return [str(nums[0])]
        res=[]
        l=0
        r=0
        cur=0
        while(cur<n):
            while(cur<n and nums[cur]-nums[r]<=1):
                r=cur
                cur+=1
            if(l==r):
                res.append(str(nums[l]))
            else:
                res.append(str(nums[l])+"->"+str(nums[r]))
            l=cur
            r=cur
        return res
```
![在这里插入图片描述](https://pic.leetcode-cn.com/e18a80fbf6ac2679c1ed359ec9113d7d1bfb13ed0d31c6dce14362ce4c0a9293.png)