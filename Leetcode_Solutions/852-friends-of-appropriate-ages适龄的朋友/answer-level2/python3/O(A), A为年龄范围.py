```
class Solution:
    def numFriendRequests(self, ages: List[int]) -> int:
        cage = [0 for _ in range(121)] 
        for i in ages:
            cage[i] += 1  #对每个年龄计数
        
        for i in range(1,121):
            cage[i] += cage[i-1] #储存包含当前及小于当前所有年龄的人数
        
        ans = 0
        for i in range(121):
            tar = i//2+7
            if tar>=i: continue  #自身不可能有满足条件的请求对象则跳过
            ans += (cage[i]-cage[tar]-1)*(cage[i]-cage[i-1])  
            #(所有满足年龄的人数-1)*当前年龄的人数即当前年龄所有人会发出的请求总数
            #上面的-1是因为自己不会对自己发出请求
        return ans
```
