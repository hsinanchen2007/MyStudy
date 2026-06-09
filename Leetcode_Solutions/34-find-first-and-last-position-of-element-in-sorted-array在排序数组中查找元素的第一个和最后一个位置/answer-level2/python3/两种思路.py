第一种是：先二分查找找到一个target，然后向左向和右遍历得到起始点和终点的位置。
第二种是：先后二分查找起始点和终点。
第一种后半段明显复杂度是线性复杂度。

第一种：

    def searchRange(self, nums: List[int], target: int) -> List[int]:
        if not nums:
            return [-1,-1]

        i=0
        j=len(nums)-1
        while i!=j:
            ij=i+(j-i)//2
            if nums[ij]>=target:
                j=ij
            else:
                if ij==i:
                    i+=1
                else:
                    i=ij
        p=i
        if nums[p]!=target:
            return [-1,-1]

        res=[]

        k=p
        if k==0:
            res.append(0)
        else:
            while nums[k-1]==target:
                k-=1
                if k==0:
                    break
            res.append(k)

        k=p
        if k==len(nums)-1:
            res.append(k)
        else:
            while nums[k+1]==target:
                k+=1
                if k==len(nums)-1:
                    break
            res.append(k)
        return res

第二种：

    def searchRange(self, nums: List[int], target: int) -> List[int]:
        if not nums:return [-1,-1]

        i=0
        j=len(nums)-1
        while i!=j:
            ij=i+(j-i)//2
            if nums[ij]<target:
                if i==ij:
                    i+=1
                else:
                    i=ij
            else:
                j=ij
        kaishi=i
        if nums[kaishi]!=target:
            return [-1,-1]

        i=0
        j=len(nums)-1
        while i!=j:
            ij=i+(j-i)//2
            if nums[ij]>target:
                j=ij
            else:
                if ij==i:
                    i+=1
                else:
                    i=ij
        if nums[i]==target:
            return [kaishi,i]
        else:
            return [kaishi,i-1]