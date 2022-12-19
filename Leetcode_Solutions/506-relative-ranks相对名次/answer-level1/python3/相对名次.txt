✔ Your runtime beats 84.5 % of python3 submissions
  ✔ Your memory usage beats 93.33 % of python3 submissions (14 MB)
```
 s,dic,start = sorted(nums,reverse=True),{},1
       for i,val in enumerate(s):
           if start == 1:
               dic[val] = "Gold Medal"
           if start == 2:
               dic[val] = "Silver Medal"
           if start == 3:
               dic[val] = "Bronze Medal"
           if start > 3:
               dic[val] = str(start)
           start+=1
       res = []
       for i in range(len(nums)):
           res.append(dic.get(nums[i]))
       return res

```