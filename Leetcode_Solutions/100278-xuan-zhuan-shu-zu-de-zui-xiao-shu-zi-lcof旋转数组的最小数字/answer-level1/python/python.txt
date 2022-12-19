class Solution(object):
    def minArray(self,numbers):
        if not numbers:
            return 
        if numbers[0]<numbers[-1]:
            return numbers[0]
        left,right = 0,len(numbers)-1
        while left<right:
            mid = (left+right) >> 1
            if numbers[mid]>numbers[right]:
                left = mid+1
            elif numbers[mid] <numbers[right]:
                right = mid 
            else:
                right-=1
        return numbers[left]

    def minArray(self,numbers):
        if not numbers:
            return
        if len(numbers)==1:
            return numbers[-1]    
        if numbers[0]<numbers[-1]:
            return numbers[0]

        mid = (len(numbers)-1)>> 1
        if numbers[mid]>numbers[-1]:
            return min(numbers[0],self.minArray(numbers[mid+1:]))
        elif numbers[mid]<numbers[-1]:
            return min(numbers[0],self.minArray(numbers[:mid+1]))
        else:
            return min(numbers[0],self.minArray(numbers[:-1]))
        

     



