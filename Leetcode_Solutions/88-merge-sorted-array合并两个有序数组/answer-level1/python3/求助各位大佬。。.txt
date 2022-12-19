class Solution:
	def merge(self, nums1, m: int, nums2, n: int) -> None:
		"""
		Do not return anything, modify nums1 in-place instead.
		"""
		i=0
		j=0
		if m==0:
			nums1=nums2
            
		else:

			while i<m+n-1 and j<n:
				if nums2[j]>=nums1[i] and nums2[j]<=nums1[i+1]:
					nums1.insert(i+1,nums2[j])
					nums1.pop()
					i=i+1
					j=j+1
				elif nums2[j]<nums1[i]:
					nums1.insert(i,nums2[j])
					nums1.pop()
					j=j+1
				elif nums2[j]>=nums1[i] and nums1[i+1]==0:
					#print(nums1[i],nums2[j])
					nums1[i+1]=nums2[j]
					i=i+1
					j=j+1
				else:
					i=i+1
求助各位大佬......
我本地输出时候对于
nums1 =[0]
m=0
nums2 = [1]
n=1 
也是正确的啊，它为啥这上面老显示我不对，显示输出0.
if m==0:
			nums1=nums2
这两行运行没问题吧