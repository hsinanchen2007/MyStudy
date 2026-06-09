### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int search(int[] nums, int target) {
	        int be=0;
	        int en=nums.length-1;
	        int inter=(be+en)>>1;
	        while(be<=en){
	            if(nums[be]<=nums[inter]&&nums[inter]<=nums[en]) {//左右都有序，按正常的二分查找进行
	            	if(nums[inter]>target){
                        en=inter-1;
                        inter=(be+en)>>1;
                    }
                    else if(nums[inter]<target) {
                        be=inter+1;
                    	inter=(be+en)>>1;
                    }
                    else 
                         return inter;	
                             	
	            }
	            else if(nums[inter]<=nums[en])//右边有序
	            {
	                if(nums[inter]<=target&&target<=nums[en]){//是否在有序的区间里
	                    be=inter;
	                    inter=(be+en)>>1;
			            if(nums[inter]>target){
		                    en=inter-1;
		                    inter=(be+en)>>1;
		                }
			            else if(nums[inter]<target) {
			                be=inter+1;
			            	inter=(be+en)>>1;
			            }
		                else
	                        return inter;
	                }
	                else {//否则在另一边，将另一边定义为新区间
	                    en=inter-1;
	                    inter=(be+en)>>1;
	                }
	            }
                else {//左边有序
	                if(nums[be]<=target&&target<=nums[inter]){//是否在有序的区间里
	                    en=inter;
	                    inter=(be+en)>>1;
                        if(nums[inter]>target){
                            en=inter-1;
                            inter=(be+en)>>1;
                            }
                        else if(nums[inter]<target) {
                            be=inter+1;
                            inter=(be+en)>>1;
                        }
                        else 
                        return inter;
	                }
	                else {//否则在另一边,将另一边定义为新区间
	                    be=inter+1;
	                    inter=(be+en)>>1;
	                }   
	            }
	        }
	        return -1;
	    }
}
```