```
public static void merge(int[] nums1, int m, int[] nums2, int n) {
		 int k=0;//计数器
		 if(m==0) {
			 for(int i=0;i<nums2.length;i++) {
				 nums1[i]=nums2 [i];
			
			 }
			 return;
		 }
		 for(int i=0;i<nums2.length;i++) {
	    	//小于开头元素
			 if(nums2[i]<nums1[0]) {
	    		exchange(nums1, 0);
	    		nums1[0]=nums2[i];
	    		k++;
	    		continue;
	    		
	    	}    	
	    	for(int j=0;j<nums1.length;j++) {
	    		//大于末尾元素
	    		if(nums2[i]>nums1[m+k-1]) {
	    			nums1[m+k]=nums2[i];
	    			k++;
	    			break;
	    		}
	    		//正常交换
	    		if(j+1<nums1.length&&nums2[i]>=nums1[j]&&nums2[i]<=nums1[j+1]) {
	    			exchange(nums1, j+1);
	    			nums1[j+1]=nums2[i];
	    			k++;
	    			break;
	    		}
	    		
	    	}
	     }
	    }
	 public static void exchange(int[] nums,int index) {
		 for(int i=nums.length-1;i>index;i--) {
			 nums[i]=nums[i-1];
		 }
		 nums[index]=0;
	 }
```
思路：
准备工作：
定义一个计数器。这个计数器用于统计往nums1添加的个数。
编写exchange函数。这个函数用于将数组整体后移一位。末尾元素移动到第一个元素。
整体思路是：
判断m是否等于0，等于0直接挨个添加；
判断nums2的元素是否比nums1的第一个元素小，如果小直接整体移动，continue；
判断是否比nums1的末尾元素大，如果大，直接末尾添加；
然后是正常情况，判断是否在某个元素之间，break；

看完了我觉得我是笨比的点赞送我上去，纪念笨比的日子哈哈哈哈哈哈哈哈哈开熏！
