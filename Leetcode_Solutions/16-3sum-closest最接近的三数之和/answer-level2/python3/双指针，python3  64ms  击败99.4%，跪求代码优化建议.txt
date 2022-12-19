解题方案：双指针法，左侧i固定，中间为左指针j初始j=i+1，右侧指针k初始k=n-1。
每次进入jk双指针区间时，首先判断最小和nums[i]+nums[j]+nums[j+1]是否大于target，或最大和nums[i]+nums[k-1]+nums[k]是否小于target，若成立则判断是否是当前最优解，后退出本次扫描，更新i进入下一轮；否则进入jk区间进行扫描，每次根据当前的和summ与target的大小关系更新j或者k，且跳过可能的重复值，不过如果有target==summ出现则直接返回target(题设只有一个解)。

跪求各位大佬看看我的代码有什么可以优化的看地方，刚学python写完看的很难受，感觉有可以优化的语句可是自己不会。

下面是代码：
```
class Solution:
    def threeSumClosest(self, nums: List[int], target: int) -> int:
        nums.sort()
        n = len(nums)
        if n<3: return 0
        flag = 1000
        result = 0
        for i in range(n-2):
            j,k = i+1,n-1
            if i>0 and nums[i-1]==nums[i]: continue
            while j<k:
                ## 判断区域内最大值是否小于target，或最小值是否大于target
                ## 成立则稍做判断(是否是当前最优解)后退出循环，否则利用双指针进行扫描
                min_sum = nums[i]+nums[j]+nums[j+1]
                max_sum = nums[i]+nums[k]+nums[k-1]
                if min_sum > target:
                    diff = min_sum - target
                    if diff < flag:
                        flag,result = diff,min_sum 
                    break
                elif max_sum < target:
                    diff = target - max_sum
                    if diff < flag:
                        flag,result = diff,max_sum
                    break
                else:
                    ## 正常双指针扫描
                    summ = nums[i]+nums[j]+nums[k]
                    diff = abs(target-summ)
                    if diff < flag:
                        flag,result = diff,summ 
                    ## 指针移动，且跳过重复值
                    if summ < target:
                        j += 1
                        while j<k and nums[j]==nums[j-1]: j += 1
                    elif summ > target:
                        k -= 1
                        while j<k and nums[k]==nums[k+1]: k -= 1
                    else:
                        return target
        return result
```

