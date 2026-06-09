本题运用了二分查找的思想，时间复杂度为O(logn)

值得注意的是，mid = (l+r)//2，为向下取整整除，所以当 l=i,r=i+1时，mid的值将等于l

此时已经到达越出[l, r]边界的临界点，再进行下一步l = mid+1，则会使l=r

此时已经可以表明在这个数列中没有要查找的元素，则该查找元素应该插入的位置，就在当前位置的下一个，即l+1

        if(not nums):
            return 0
        l=0
        r=len(nums)-1

        while(l<=r):
            mid=(l+r)//2
            if(nums[mid]==target):
                return mid
            elif(nums[mid]>target):
                r=mid-1
            else:
                l=mid+1
        return l
