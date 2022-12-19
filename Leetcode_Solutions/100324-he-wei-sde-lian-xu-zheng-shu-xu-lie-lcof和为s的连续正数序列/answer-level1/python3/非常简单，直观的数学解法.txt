萌新第一次写解题思路，出现什么错误，诸位大佬请多多包涵。
```
class Solution:
    def findContinuousSequence(self, target: int) -> List[List[int]]:
        ans=[]
        if target==1 or target==2:
            return []
        
        for n in range(target//2+1,1,-1):
            mean=target/n
            
            if n%2==1 and (mean-(n-1)/2)>0 and target%n==0:     # odd
                ans.append([i for i in range(int(mean-(n-1)/2),int(mean+(n+1)/2))])

            elif n%2==0 and (mean+0.5-n/2)>0 and target%n==0.5*n:     # even
                ans.append([i for i in range(int(mean+0.5-n/2),int(mean+0.5+n/2))])
                
        return ans
```


思路：因为题目中要求的是正整数序列,我们不妨把最后的序列分为两种情况：有奇数个数字，有偶数个数字。

情况1: 在有奇数个数字的情况：
数列的中间值即为平均值：mean = target/n, 且平均值必须为整数。只需判断数列最左边的数是大于0, 即可通过数列连续的特点输出数列, 数列最小的值为 int(mean-(n-1)/2)

情况2：在有偶数个数列的情况：
这种情况下， mean = target/n 必定是以 0.5 结尾的数， 比如 10 分为 4个数, 均值为 2.5。同样需要比较数列最小值是否大于0，最小的值为 int(mean+0.5-n/2)

因为 n>=2 且 n<=target//2 + 1, 所以只需对这个范围做循环并输出所有可能的数组即可。 

![1.jpg](https://pic.leetcode-cn.com/4e79fb9adb3d2de47f3f513df6908560602727f733f4206e761645c2abb0cd33-1.jpg)


