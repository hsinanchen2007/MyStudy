```
class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        res=[]
        list01=nums
        list01.sort()
        for i in range(len(list01)-2):
            if list01[i]>0 or list01[-1]<0:#开头为正，或者末尾为负都不可能满足要求
                break
            if i>0 and list01[i]==list01[i-1]:#重复的元素不用遍历
                continue
            l=i+1
            r=len(list01)-1
            while l<r:
                if list01[i]+list01[l]+list01[r]==0:
                    res.append([list01[i],list01[l],list01[r]])
                    l+=1
                    r-=1
                    while l < r and list01[l] == list01[l - 1]:#重复的元素不用再计算
                        l += 1
                    while l < r and list01[r] == list01[r + 1]:
                        r -= 1

                else:
                    if list01[i] + list01[l] + list01[r] < 0:
                        l+=1
                        while l<r and list01[l] == list01[l - 1]:
                            l+=1
                    else:
                        r-=1
                        while l < r and list01[r] == list01[r + 1]:
                            r -= 1
        return res

```
