先把nums数组存入哈希表，再对nums数组排序
再遍历就行，但是要考虑k=0的特殊情况


    def findPairs(self, nums: List[int], k: int) -> int:
        dic={}
        for i in nums:
            if not dic.get(i):
                dic[i]=1
            else:
                dic[i]+=1
        
        res=0
        nums.sort()
        if k==0:
            for m in nums:
                if dic[m]!=1:
                    res+=1
                    dic[m]=1
        else:
            for j in nums:
                if dic[j]!=0:
                    if dic.get(j+k):
                        res+=1
                dic[j]=0
        
        return res