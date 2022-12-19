class Solution:
	def findMedianSortedArrays(self, nums1, nums2) -> float:
		c=sorted(nums1+nums2)
		if len(c)%2==0:
			return (c[len(c)//2]+c[len(c)//2-1])/2
		else:
			return float(c[(len(c)-1)//2])
