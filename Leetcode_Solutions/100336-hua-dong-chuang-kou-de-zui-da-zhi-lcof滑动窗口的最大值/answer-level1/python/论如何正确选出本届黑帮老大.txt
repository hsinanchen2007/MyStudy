![image.png](https://pic.leetcode-cn.com/352dad511d16ba0d12884be441f5951569d0a66a03ecd83620c0b799941b36a3-image.png)

```
    def maxSlidingWindow(self, nums, k):
        if nums == []:
            return []
        if k == 1:
            return nums
        ret = [max(nums[0:k])]
        begin,end = 0,k-1
        while end < len(nums)-1:
            end += 1
            #如果新来的人是大哥，那么本届大哥就是他
            if nums[end] >= ret[-1]:
                ret.append(nums[end])
                begin += 1
                continue
            else:
                #即将离开的人是不是大哥，是的话重新选大哥，不是的话你大哥还是你大哥
                if nums[begin] == ret[-1]:
                    begin += 1
                    ret.append(max(nums[begin:end+1]))
                else:
                    begin += 1
                    ret.append(ret[-1])
        return ret
```
