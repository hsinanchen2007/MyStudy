题中要求时间复杂度为log(m+n),解决这个问题必须用二分查找的思想。之前的题解很多着重于找到那个把两个数组分成两等分的割（cut）。我的方法取名一个名字的话可以叫二分舍弃法；首先我们简单地理解一下中位数的概念，中位数是这样一个数，它把一个有序数组分成两等份，位于它之前的数的个数等于它之后的数的个数。因此我们可以根据这个特点来找到中位数。
算法的伪代码如下：
   1：两个数组a，b，它们的长度分别为m，n，假设m<n；
        1）当m=0时 返回b的中位数；
        2）当m=1时，把这个数与b的中位数比较可得出中位数（根据n是偶数与否会有两种可能）进入下一步
   2：如果a的中位数大于b的中位数，则舍弃a的位于中位数之后的数，个数为m/2；同时b舍弃从0开始的m/2个数；反之，则舍弃a的位于中位数之后的数，个数为m/2；同时b舍弃从后往前数的m/2个数；
   3：如果a的数目大于2，返回第2步
   4：此时a还有两个数，设为a1，a2；把a1，a2与b的中位数比较即可得出整个数组的中位数
有如下两个数组，图中标出了数组的mid位置
![4-1.png](https://pic.leetcode-cn.com/6ed4864a1e770e4e1b5c8ba781c47e47abfc5892f884ebfc095385e8d160f456-4-1.png)
因为19>16，所以可以对称的去掉数组一的最后三个数和数组二的开头三个数，如图所示
![4-1.png](https://pic.leetcode-cn.com/a80048fd375c8ba800ebab02fa4f7801502ab1709147b1eacc09603f4ccba7e7-4-1.png)
现在只看白色部分，重新计算出mid位置13<20,
![4-1.png](https://pic.leetcode-cn.com/00e9692420119992462f8abf7cef432784f660aad218bf31e6474f2a8c84b4ad-4-1.png)
最后根据中位数必然在[19,20]和[13，15，19]中取得，
![4-1.png](https://pic.leetcode-cn.com/d4f858979567d7af4a857db1179556c1e8632306a0ff0f04d97ede2b6a5ea215-4-1.png)


代码如下
```

class Solution {
    public double findMedianSortedArrays(int[] nums1, int[] nums2) {
         if(nums1.length<nums2.length){int tem[];tem=nums1;nums1=nums2;nums2=tem;}
		 int sort[];
		 int left1=0,right1=nums1.length-1,mid1=(right1+left1)/2,left2=0,right2=nums2.length-1,mid2=(right2+left2)/2,
	        		currentLength1=nums1.length,currentLength2=nums2.length,tem;
		 if(nums2.length==0)//数组二长度为0
			 if(nums1.length%2==0) return (nums1[mid1]+nums1[mid1+1])/2.0;//数组一长度为偶数
			 else  return nums1[mid1];//奇数
		 else if (nums2.length==1) {//数组二长度为一，为b
			 if(nums1.length==1) return (nums1[0]+nums2[0])/2.0;//数组一长度也为一
			 else {
				 if(currentLength1%2==0) {//偶数 设中间的两个数为：a1，a2；有三种可能的排列关系：
					 if(nums2[0]<=nums1[mid1]) return nums1[mid1];//b,a1,a2
					 else if (nums2[0]<=nums1[mid1+1]) return nums2[0];//a1,b,a2
					 else return nums1[mid1+1];//a1,a2,b
				 }
				 else {//长度为奇数，设中间的三个数为a1,a2,a3
					sort=new int[] {nums2[0],nums1[mid1],nums1[mid1-1],nums1[mid1+1]};//对a1,a2,a3,b排序 
					Arrays.sort(sort);
					return (sort[1]+sort[2])/2.0;//取中间两位的平均值
				}
			}
		}
	     while(currentLength2>2) {//数组二的长度大于二，根据序号nums1[mid1]与nums2[mid2]的大小减小它的长度
	        if(nums1[mid1]<nums2[mid2]) {//数组二的上半部分与中位数的值无关，去掉这一部分，同时也去掉相同数目的数组一的下半部分；
	        	left1=left1+(right2-left2)/2;//去掉(right2-left2)/2个数
	        	right2=right2-(right2-left2)/2;
	        }
	       	else {
				right1=right1-(right2-left2)/2;//去掉上半部分
				left2=left2+(right2-left2)/2;
			}
	        mid1=(right1+left1)/2;
	        mid2=(right2+left2)/2;
	        currentLength1=right1-left1+1;
	        currentLength2=right2-left2+1;
	       }//此时数组二变成[b1,b2],数组一为[...,a1,a2,...]或者[...,a3,a1,a2,...]或者[...,a3,a1,a2,a4,...]
	     int a1=nums1[mid1],a2=nums1[mid1+1],a3=0,a4=0,
	    		 b1=nums2[mid2],b2=nums2[mid2+1];
	     if(mid1-1>=0)
	    		a3=nums1[mid1-1];
	     if(currentLength1%2==0) {//第一个数组剩余的数的个数为偶数
	    	 if(mid1+2<nums1.length){
	    		 a4=nums1[mid1+2];
	    		 sort=new int[] {a1,a2,b1,b2,a3,a4};//[...,a3,a1,a2,a4,...][b1,b2]
	 			Arrays.sort(sort);
				return (sort[3]+sort[2])/2.0;
	    	 }
	    	 sort=new int[] {a1,a2,b1,b2};//[...,a1,a2,...][b1,b2]
			Arrays.sort(sort);
			return (sort[1]+sort[2])/2.0;
	     }else {//第一个数组剩余的数的个数为奇数//[b1,b2][...,a3,a1,a2,...]
	    	 sort=new int[] {a1,a2,a3,b1,b2};
			Arrays.sort(sort);
			return sort[2];
		}
    }
}
```

有什么改进的建议可以随时和我交流哦！

