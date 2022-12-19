**方法1**
利用左右两个指针分别对两个数组进行遍历，直至到达指定位置（即中位数的位置）后返回中位数的值。这种方法利于理解，但是由于时间复杂度为O(m+n)，并不能满足题目的要求。

```
double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size){
    int left=0, right=0;
	int len = nums1Size+nums2Size;
	int ret[len];
	memset(ret, 0, sizeof(int)*(len));
	int i=0;
	while((left<nums1Size)&&(right<nums2Size)){
		if (nums1[left]<nums2[right]){
			ret[i] = nums1[left];
			left++;
		}else{
			ret[i] = nums2[right];
			right++;
		}
		i++;
	}
	

	while(right<nums2Size && i<len){
		ret[i] = nums2[right];
		i++;
		right++;
	}

	while(left<nums1Size&& i<len){
		ret[i] = nums1[left];
		i++;
		left++;
	}
	
	
	if(len%2==0){
		return ((ret[len/2]+ret[len/2-1])/2.0);
	}else{
		return ret[len/2];
	}
}
```

**方法2**
根据中位数的定义，我们假设两个数组分别为A和B，并且两个数组分别在索引为i和j处分为两半，具体如下图所示。i的初值设置由二分法设置，即为数组A的中位数索引。然后根据图中定义的两种情况去改变iMin和iMax的值，进而增加或者减少i，随着i的变化，由公式2可得j也在发生变化。因此，可得如下代码，因为每次都是二分地去得到i的值，所以时间复杂度为O(log(m+n))。
![image.png](https://pic.leetcode-cn.com/cdd273ae935b78d3e785f9f367eaf0e25e16e82d66acdb064649869c4905c2f6-image.png)

```
#define MAX(a,b) (((a)>=(b))?(a):(b))
#define MIN(a,b) (((a)<=(b))?(a):(b))
double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size){
	int iMin=0;
	int iMax = nums1Size;
	if(nums1Size>nums2Size){
		return findMedianSortedArrays(nums2, nums2Size, nums1, nums1Size);
	}
	while(iMin<=iMax){
		int i = (iMin+iMax)/2;
		int j = (nums1Size+nums2Size+1)/2-i;
		if(j!=0 && i!=nums1Size && nums2[j-1]>nums1[i]){
			iMin = i+1;
		}else if( i!=0 && j!=nums2Size && nums1[i-1]>nums2[j] ){
			iMax = i-1;
		}else{
			int maxLeft = 0;
			if(i==0){
				maxLeft = nums2[j-1];
			}else if(j==0){
				maxLeft = nums1[i-1];
			}else{
				maxLeft =MAX(nums1[i-1], nums2[j-1]);
			}
			if((nums1Size+nums2Size)%2==1){
					return maxLeft; 
				}
			
			int minRight = 0;
			if(i==nums1Size){
				minRight = nums2[j];
				
			}else if(j==nums2Size){
				minRight = nums1[i];
			}else{
				minRight = MIN(nums1[i],nums2[j]);
			
			}
				
			return (maxLeft+minRight)/2.0;
	
		}
		
	}
	
	return 0.0;
	
}
```
