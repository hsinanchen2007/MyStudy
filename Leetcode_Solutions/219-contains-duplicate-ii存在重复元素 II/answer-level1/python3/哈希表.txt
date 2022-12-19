```
def containsNearbyDuplicate(nums, k):
    num_dic={}
    j=0
    for i in nums:
        if i not in num_dic:
            num_dic[i]=j
            j+=1
        elif j-num_dic[i]<=k:
            return True
        else:
            num_dic[i]=j
            j+=1
        return False
```
