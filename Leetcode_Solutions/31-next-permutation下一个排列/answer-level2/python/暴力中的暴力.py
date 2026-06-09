
```python []
class Solution(object):
    def nextPermutation(self, nums):
        num1=nums[::-1]
        a=num1[0]
        c=0
        list1=[]
        for b in num1:
            if b>a:
                list1.append(b)
                a=b
                c+=1
            elif b==a:
                list1.append(b)
                c+=1
            else:
                break
        d=len(nums)-c-1
        e=nums[d]
        g=0
        for f in range(len(list1)):
            if list1[f]>e:
                break
            else:
                g+=1
        h=len(nums)-g-1
        j=nums[h]
        nums[d]=j
        nums[h]=e
        list2=nums[d+1:]
        list2.sort()
        nums[d+1:]=list2
        return nums
```



