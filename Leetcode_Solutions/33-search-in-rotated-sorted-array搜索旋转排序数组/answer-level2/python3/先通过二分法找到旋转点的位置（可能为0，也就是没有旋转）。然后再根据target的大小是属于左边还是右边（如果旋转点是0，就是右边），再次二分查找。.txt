    def search(self, nums: List[int], target: int) -> int:
        if not nums:return -1

        i=0
        j=len(nums)-1
        while i!=j:
            ij=i+(j-i)//2
            if nums[ij]>nums[j]:
                if ij==i:
                    i+=1
                else:
                    i=ij
            else:
                j=ij
        fenkai=i

        if fenkai!=0 and target>=nums[0]:
            nums_zuo=nums[:fenkai]
            i=0
            j=len(nums_zuo)-1
            while i!=j:
                ij=i+(j-i)//2
                if nums_zuo[ij]>=target:
                    j=ij
                else:
                    if ij==i:
                        i+=1
                    else:
                        i=ij
            if nums_zuo[i]==target:
                return i
            else:
                return -1
        else:
            nums_you=nums[fenkai:]
            i=0
            j=len(nums_you)-1
            while i!=j:
                ij=i+(j-i)//2
                if nums_you[ij]>=target:
                    j=ij
                else:
                    if ij==i:
                        i+=1
                    else:
                        i=ij
            if nums_you[i]==target:
                return i+fenkai
            else:
                return -1