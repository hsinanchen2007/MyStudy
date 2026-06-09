### 解题思路


### 代码
设置计数器count(记录遍历过程中出现nums[i]>nums[i+1]的个数),遍历中途出现count>=2,则直接返回false;
出现nums[i]>nums[i+1]时：
当前索引为i时，对nums[i-1]与nums[i+1]进行大小判断,根据判断结果,对nums[i]和nums[i+1]的值进行合适的更新。
```java
class Solution {
    public boolean checkPossibility(int[] nums) {
    	int count = 0;  //count遍历过程出现nums[i]>nums[i+1]的次数
    	int i = 0;
    	while(i<nums.length-1) {
    		if(nums[i]<=nums[i+1]) {   //nums[i]<=nums[i+1]符合条件,i++
    			i++;
    		}else if(nums[i]>nums[i+1]) {
    			count++;          //出现nums[i]>nums[i+1],首先count++，
    	    	if(count>=2) {    //对count进行判断,若当前出现count>=2，则直接返回false
    	    		return false;
    	    	}
    			if(i==0) {        //nums[i]>nums[i+1]出现在首位,则将nums[0]=nums[1]
    				nums[i] = nums[i+1];
    			}else if(i>0) {       //nums[i]>nums[i+1]出现在首个元素之外的数组中,则用nums[i+1]与nums[i-1]进行大小比较
    				if(nums[i+1]>=nums[i-1]) {          //nums[i+1]大于或等于nums[i-1]时,将nums[i]替换成nums[i+1]
    					nums[i]=nums[i+1];
    				}else if(nums[i+1]<nums[i-1]) {     //nums[i+1]小于nums[i-1]时,将nums[i+1]替换成nums[i]
    					nums[i+1] = nums[i];
    				}
    			}
    			i++;
    		}
    	}
    	return true;
    }
}
```