![1.png](https://pic.leetcode-cn.com/cdad27372044e2fcfab43cad2166941325d80a91a8b826d0168ffb34ae030f8c-1.png)

```
public class FirstMissingPositive {
    public int firstMissingPositive(int[] nums) {
    	if(nums.length == 0) return 1;
    	boolean[] barrel = new boolean[nums.length+1];
    	for(int i = 0; i < nums.length; i++) {
    		if(nums[i] > 0 && nums[i] <= nums.length) {
    			barrel[nums[i]] = true;
    		}
    	}
    	for(int i = 1; i < barrel.length; i++) {
    		if(!barrel[i]) return i;
    	}
    	return barrel.length;
    }
}
```
