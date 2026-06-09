### 解题思路
实际上就是二分查找
先查找target 所在的索引位置i，然后查找周围和他值相同的索引就可以了


### 代码

```java
class Solution {
	public static int binarySearch(int val,int[] list,int start,int end){		
		int mid=start+((end-start)>>1);
		if(mid<0||start>=end&&list[start]!=val)
			return -1;
		if(list[mid]==val){
			return mid;
		}
		
		if(list[mid]<val){
			return binarySearch(val,list,mid+1,end);
		}else{
			return binarySearch(val,list,start,mid-1);
		}
	}
	
    public static int[] searchRange(int[] nums, int target) {
    	int[] result={-1,-1};
    	if(nums.length==0){
    		return result;
    	}
    	//获取目标其中一个所在的索引
    	int tmp=binarySearch(target,nums,0,nums.length-1);
    	if(tmp==-1){
    		return result;
    	}
    	int low=tmp,high=tmp;
    	int i=1,j=1;
    	for(;tmp+i<nums.length&&nums[tmp+i]==nums[tmp];i++);
    	for(;tmp-j>=0&&nums[tmp-j]==nums[tmp];j++);
    	result[0]=low-j+1;
    	result[1]=high+i-1;
    	return result;
    }
}
```