```
class Solution:
    def findShortestSubArray(self, nums: List[int]) -> int:
        if nums==[]:
            return 0
        dic={}
        ##[nums,start,end]
        rs=0
        rs_list=[0,0,0]
        for i in range(nums.__len__()):
            if dic.get(nums[i])==None:
                dic[nums[i]]=[1,i,i]
            else:
                tmp=dic.get(nums[i])
                dic[nums[i]][0]+=1
                dic[nums[i]][2]=i
                
            if dic[nums[i]][0]>rs_list[0]:#频数高于当前最高频数即更新
                rs_list=dic[nums[i]][:]
            elif dic[nums[i]][0]==rs_list[0]:
                if (dic[nums[i]][2]-dic[nums[i]][1])<(rs_list[2]-rs_list[1]):#相同频数下优先保留最短长度的数组
                    rs_list=dic[nums[i]][:]
        return rs_list[2]-rs_list[1]+1
```
