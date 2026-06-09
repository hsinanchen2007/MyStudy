看了一下很多同学的答案都没有写去重。受上一题 [三数之和](https://leetcode-cn.com/problems/3sum/solution/hua-jie-suan-fa-15-san-shu-zhi-he-by-guanpengchn/) 的启发，分析一下去重的原理，以及这题是否可以进行去重。 

**先说结论：去不去重不影响结果，但是去重效率更高**

**part1 我们来看看在三数之和那道题中为什么可以去重。**
假设一开始指针位置是。  
![image.png](https://pic.leetcode-cn.com/239f6dc193ded8d69fe46c07b9c08482e4cbc13d4d07ff5b7210852d0cb5d375-image.png)

这时候所有可能的组合按和从小到大排列为：S1={[0,0,1],[0,0,2],[0,1,2],[0,0,3],[0,1,3],[0,2,3]}

(当然，实际上组合里的这些所有可能并不会被全部遍历，因为我们事先排好序，所以可以根据其和与目标值的大小        关 系，移动指针，使其和有目的的变大或者变小。这也是在解决三数之和这个问题时，排序给我们带来查找效率提       升的原因。)

在一轮之后,假设不去重，i指针指向第二个0,即此时指针位置如下：

![image.png](https://pic.leetcode-cn.com/cd12cec308f0c83b0ef17e8eb4bfc109e4f4cb959d4049dea2005182c8f6ab0c-image.png)
我们再按其和从小到大排序，列举一下所有可能的组合，记为S2：

S2={[0,1,2],[0,1,3],[0,2,3]}

这时我们不难发现一个规律，S2是S1的子集,且S1中组合的和的下界比S2要小，上界是一样的。

也就是说，S2中取到最优值的组合（比如target=5,那么最优组合为[0,2,3]），在S1中肯定也能取到相同的组合。
而S1中能取到最优值的组合（比如target=1，那么最优组合为[0,0,1]），在S2中不一定能取到（因为S2中没有[0,0,1]      ）

分析到这里，我们就知道为什么三数之和中可以进行去重操作了，而且一定要保留第一个数，去掉后面重复的数。因      为第一个数的可能组合的集合范围更大。

同理，如果有n个重复的数字，那么Sn∈……S3∈S2∈S1。


**part2 有了上面的结论，再看这道题可不可以去重就很简单了。**
因为在S2中能找到的最接近target的组合，在S1中也一定能找到，所以当然可以利用去重的判断来提高效率啦~

下面是我的代码，不知道有没有讲清楚。
我也是新手一枚，欢迎大家批评指正~    


```
class Solution(object):
    def threeSumClosest(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: int
        """        
        
        length = len(nums)
        if length<=2: return None

        nums = sorted(nums)
        ans = nums[0]+nums[1]+nums[2]
        for i in range(length-2):     
            #如果有两个数重复，前面的那个的查找范围一定大于后面的。
            #所以在以后面的那个作为i指针的范围内能取到最优值的组合，前者也一定能取到。
            #而前者能取到的，后者不一定能取到。
            if i>0 and nums[i]==nums[i-1]: continue

            left = i+1
            right = length-1
            while left<right:
                if left-1>= i+1 and nums[left]==nums[left-1]:
                    left+=1
                    continue
                if right+1<=length-1  and nums[right]==nums[right+1]:
                    right-=1
                    continue
                sum = nums[i]+nums[left]+nums[right]
                det1 = abs(sum-target)
                det0 = abs(ans-target)
                if sum>target: 
                    if det1 < det0:                         
                        ans = sum                     
                    right-=1
                elif sum<target: 
                    if det1 < det0:                        
                        ans = sum  
                    left+=1
            
                else: return sum
        
        return ans
```
