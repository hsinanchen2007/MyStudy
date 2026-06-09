### 解题思路
此处撰写解题思路
分离正数和负数，在进行分类
### 代码

```java
class Solution {
    public int maximumProduct(int[] nums) {
        if(nums == null || nums.length <= 2)
            return 0;
        
        int[] numss = new int[nums.length];
		int[] nums1 = new int[nums.length];
		Arrays.sort(nums);
        int i,f = 1,t = 1,k = 0,p = 0,res = 0;
        for(i = nums.length - 1;i >= 0;i--){
            if(nums[i] < 0) {
            	numss[k] = nums[i];
            	k++;
            }
            else {
            	nums1[p] = nums[i];
            	p++;
            }
        }
        if(k == 0 || p == 0)
        	res = nums[nums.length - 1] * nums[nums.length - 2] * nums[nums.length -3];
        if(k != 0 && p != 0) {
        	if(k + p == 3)
        		res = nums[nums.length - 1] * nums[nums.length - 2] * nums[nums.length -3];
        	if(k + p > 3) {
        		if((p == 2 && k == 2) || (p <= 2 && k >= 3)) {
        			f = nums[nums.length - 1] * nums[1] * nums[0];
        			res = f;
        		}
        		if((p >= 3 && k <= 2) || (k >= 3 && p >= 3)) {
        			t = nums[nums.length - 1] * nums[nums.length - 2] * nums[nums.length -3];
        			f = nums[nums.length - 1] * nums[1] * nums[0];
        			res = t > f?t : f;
        		}
        	}
        }
        return res;
    }
}
```