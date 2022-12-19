官方题解没太看明白，自己想了两个方法，方法一是常规思路，方法二想法很简单，实现也很简单。

## 字丑请见谅O(∩_∩)O

### 解法1：依次寻找能盛水的凹槽
理想情况下，整个数组从左至右遍历一遍即可得到答案。
复杂情况下，数组某子区间需要进行二次判断方能得出结果。
![image.png](https://pic.leetcode-cn.com/430bcaa85f84c65196ae939deab48b85ac33ff3436e723c841f39f3b3dc97327-image.png)

![image.png](https://pic.leetcode-cn.com/5f0ad2844bf73f0aba4f2cdea9894e2b4f18f8919e98b36eed09f0018c1ea742-image.png)

![image.png](https://pic.leetcode-cn.com/ad919caac353c3cd082f71ba5723224d83cbd9233df1d454923c9993e760fba1-image.png)

![image.png](https://pic.leetcode-cn.com/0a2344bae5b348b2e0a87a19844a1a97a8f4d4811c3ec1f15ab8cb51bbe58da6-image.png)

程序中有对应解释，可以对照图片浏览。
```解法1：Python3 []
class Solution:
    def trap(self, height: List[int]) -> int:
        l = 0 # 左指针
        n = len(height) # 数组长度
        sum = 0 # 接雨水结果

        while l+1<n:
            if height[l]>height[l+1]: # 原则1
                h=height[l]
                l+=1
                start = l
                while l<n and height[l]<h: # 步骤2.1，寻找比h大的height
                    l+=1
                if l==n: # 说明右边的height都小于当前的h，此时要判断当前h是否作为盛水壁（即是否会接触到雨水）
                    l=start
                    try: # 如果height[l]恰好是最后一项，那么height[l+1:]没有值，max(height[l+1:])会报错
                        h=max(height[l+1:])
                    except ValueError:
                        h=0
                    if height[l]>=h:continue # 说明初始l不作为盛水壁
                    else: # 说明初始l作为盛水壁
                        end = height[l+1:].index(h)+l+1 # 与初始l围成水池的情况
                        for i in height[start:end]:
                            sum+=h-i
                        l=end # 直接从水池的右端重新开始上述循环
                else:
                    for i in height[start:l]:
                        sum+=h-i
            else:l+=1
        return sum
```

### 解法2：“水漫金山”法
![image.png](https://pic.leetcode-cn.com/b18542a9a5d1ad9bb7bcec5dfd34e77651c9427f4db659910c03d939e6ca6789-image.png)

```解法2：Python3 []
import numpy as np
class Solution:
    def trap(self, height: List[int]) -> int:
        if height==[]:return 0
        res = 0
        
        for i in range(1,max(height)+1):# 高度自下向上递增
            interval=[]
            for j in range(len(height)):# 索引从左向右遍历
                if height[j]>=i:
                    interval.append(j)
            res += (np.diff(np.array(interval)).sum()-len(interval)+1) # 一个小技巧
        
        return int(res)
```
程序中`np.diff(np.array(interval)).sum()`是一个小技巧。
interval储存的是当前循环中所有大于等于h的索引。如上图中，`height=[0,2,1,2,1,0,1,3,2,0,2]`，当`h=1`时，索引第`[1,2,3,4,6,7,8,10]`位置的值均大于等于1，记录到interval，即`interval=[1,2,3,4,6,7,8,10]`。而后将其转换成numpy数组，目的是为了使用`np.diff`，这个函数是求数组中**两两相邻数值之间的差值**，那么`np.diff(np.array(interval))=[1,1,1,2,1,1,2]`，而后将每个值减1（如索引[1,2]，他们之间不能接水，但是2-1=1，因此需要把1减掉）得到`[0,0,0,1,0,0,1]`，求和为2，即第一行能积累2体积的雨水。后续同理。。。