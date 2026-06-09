
    class Solution:
        def searchRange(self, nums: List[int], target: int) -> List[int]:
            if nums is None:
                return [-1,-1]
            f=self.searchFirstTarget(nums,target)
            e=self.searchEndTarget(nums,target)
            return [f,e]

        #二分查找元素的第一个位置
        def searchFirstTarget(self,nums,target):
            if nums is None:
                return -1
            start=0
            end=len(nums)-1
            while start<=end:
                mid=(start+end)//2
                #如果nums[mid]==target，需要进一步判断：
                if nums[mid]==target:
                    #如果此时mid是0号元素，则其一定为元素的第一个位置（没有比0号元素更左边的元素了）
                    #或者如果mid不是0号元素，但是mid的左边一个元素不等于target，同样表明其是target的第一个位置
                    if mid==0 or nums[mid-1]!=target:
                        return mid
                        break
                    #若不是以上两种情况，即mid的左边元素也等于target，此时将end=mid-1
                    else:
                        end=mid-1
                #如果nums[mid]>target，表明target在mid的左侧，因此将end=mid-1
                elif nums[mid]>target:
                    end=mid-1
                #如果nums[mid]<target，表明target在mid的右侧，因此将start=mid+1
                else:
                    start=mid+1
            return -1

        #二分查找元素的最后一个位置
        def searchEndTarget(self,nums,target):
            if nums is None:
                return -1
            start=0
            end=len(nums)-1
            while start<=end:
                mid=(start+end)//2
                if nums[mid]==target:
                    #如果mid是nums最右位置元素，则表明其是target的最后一个位置（因为没有比该位置更右的元素了）
                    #如果mid不是nums最右位置元素，但是nums的右一位元素不等于target，表明其是target的最后一个位置
                    if mid==len(nums)-1 or nums[mid+1]!=target:
                        return mid
                        break
                    #如果不是以上两种情况，即mid的右边一个元素也等于target，则将start=mid+1
                    else:
                        start=mid+1
                elif nums[mid]>target:
                    end=mid-1
                else:
                    start=mid+1
            return -1   
            
            