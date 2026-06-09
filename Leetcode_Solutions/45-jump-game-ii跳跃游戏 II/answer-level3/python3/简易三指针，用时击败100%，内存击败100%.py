![1E2B0821-8B0D-4D44-9CD8-C87189FEE3EB.png](https://pic.leetcode-cn.com/bf148828e4a37066cb605a062f369dd12f91fe1489907746efe3b29e4f54786a-1E2B0821-8B0D-4D44-9CD8-C87189FEE3EB.png)
```

class Solution(object):
    def jump(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        lenk=len(nums)
  <!-- 如果为一个元素，直接返回0 -->
        if lenk==1:return 0
        p=0
<!-- q初始化为第一次跳跃最远距离，count为一次跳跃 -->
        q=p+nums[0]
        if q>lenk-1:return 1
        r=0
        count=1
<!-- q没超过边界则继续循环 -->
        while q<lenk-1:
<!-- p小q则p不断像q移动，过程中不断更新r（本过程所能到达最远位置） -->
            while p<q:
                if p+nums[p]>r:
                    r=p+nums[p]
                    if r>=lenk:return count+1
                p+=1
<!-- p到达q，更新q到r，完成一次跳跃，count自增1 -->
            if p==q:
                if p+nums[p]>r:
                    r=p+nums[p]
                    if r>=lenk:return count+1
                q=r
                count+=1
        return count


```

p , q , r 三个指针，count用来记录跳跃数，后面会解释其作用
首先，更新q为p+num[p]，即p位置加上p位置数字值。然后不断移动p直到与q重合，过程中每移动一次p记录一下本次p趋向于q
过程中最大的p+num[p]，用r记录。就是每次p到q移动的过程中的点能跳跃到的最大值。然后p与q重合时，q移动到r的位置，即变成刚才
p向q趋近过程中所能跳跃的最大位置，此时count增加1。

（其实q指向了跳跃count次数所能到达的最远位置）

如果有什么不明白欢迎评论交流