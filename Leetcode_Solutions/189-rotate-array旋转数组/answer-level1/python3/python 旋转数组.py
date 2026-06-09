考虑一个长度为6的数组，k为4
只需要做gcd(6,4)次，步长为k的旋转
```
class Solution:
    def gcd(self,a,b):
        return a if b==0 else self.gcd(b,a%b)
    def rotate(self, nums: List[int], k: int) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        N=len(nums)
        g=self.gcd(N,k)
        for i in range(g):
            temp=nums[i]
            ind=i
            for j in range(int(N/g)-1):
                nums[ind]=nums[(ind-k+N)%N]
                ind=(ind-k+N)%N
            nums[(i+k)%N]=temp
```
