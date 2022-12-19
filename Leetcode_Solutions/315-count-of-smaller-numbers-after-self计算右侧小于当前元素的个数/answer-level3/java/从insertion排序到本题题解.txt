插入排序本身比较适合本题
```
class Solution {
    public List<Integer> countSmaller(int[] nums) {
    	//垃圾题目，非要用List作为返回值
    	List<Integer> returnData = new ArrayList<>(nums.length);
    	if(nums.length == 0) return returnData;
    	returnData.add(0);
    	for(int i = nums.length - 2; i >= 0; i--) {
    		int j = i+1;
    		for(; j < nums.length; j++) {
    			if(nums[j] >= nums[j-1]) {
    				nums[j-1] = nums[j]^nums[j-1];
    				nums[j] = nums[j]^nums[j-1];
    				nums[j-1] = nums[j]^nums[j-1];
    			}else {
    				break;
    			}
    		}
    		returnData.add(nums.length - j);
    	}
    	Collections.reverse(returnData);
    	return returnData;
    }
}
```
