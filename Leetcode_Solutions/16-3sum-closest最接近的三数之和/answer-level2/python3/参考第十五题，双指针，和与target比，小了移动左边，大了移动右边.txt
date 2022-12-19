```
        res=nums[0]+nums[1]+nums[2]
        min=abs(target-nums[0]-nums[1]-nums[2])
        list01=nums
        list01.sort()
        for i in range(len(list01)-2):
            if i>0 and list01[i]==list01[i-1]:
                continue
            l=i+1
            r=len(list01)-1
            while l<r:
                t=list01[i]+list01[l]+list01[r]
                if t==target:
                    return t
                else:
                    if list01[i] + list01[l] + list01[r] < target:
                        l+=1
                        while l<r and list01[l] == list01[l - 1]:
                            l+=1
                    else:
                        r-=1
                        while l < r and list01[r] == list01[r + 1]:
                            r -= 1
                if abs(t-target)<min:
                    min=abs(t-target)
                    res=t
        return res

```
