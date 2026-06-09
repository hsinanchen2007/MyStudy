### 解题思路
此处撰写解题思路
1.两个整型数组长度不能同为0
2.数组相加后排序，从大到小
3.判断列表长度，奇数偶数
4.判断的所有下表减一，返回中间数
### 代码

```python
class Solution(object):
    def findMedianSortedArrays(self, nums1, nums2):
    	num3=[]
    	if  len(nums1)==0 and len(nums2)==0:
    		return 0
    		pass
    	else:
	    	num3=nums1+nums2
	    	num3.sort()
	    	c=len(num3)
	    	if c%2==0:
	    		z1=int(c/2)
	    		z2=z1+1
	    		sd=(float(num3[z1-1])+float(num3[z2-1]))/2
	    		return sd
	    	else:
	    		z1=int((c-1))/int(2)
	    		z2=int(z1)+1
	    		return float(num3[z2-1])
```