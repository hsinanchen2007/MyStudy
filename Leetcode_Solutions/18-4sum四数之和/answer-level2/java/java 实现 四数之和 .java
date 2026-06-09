
# 借助求三数之和，求解四数之和

```java []
class Solution {
    Set<List<Integer>> res = new HashSet<>();
    int[] nums;
    int max = Integer.MIN_VALUE;
    int len = 0, sum = 0;
    
    public List<List<Integer>> fourSum(int[] nums, int target) {
        
        this.nums = nums;
        len = nums.length;
        
        if (nums == null || len < 4)
			return new ArrayList<>();
        
        //要先对数组进行排序,判重时，可以跳过
        Arrays.sort(nums);
        
        max = Math.max(max, nums[len-1]);
        if (4 * nums[0] > target || 4 * max < target)
			return new ArrayList<>();
        
        int z;
        for(int i=0; i<len-3; i++){
            z = nums[i];
            
            if (i > 0 && z == nums[i - 1])// avoid duplicate
				continue;
            
            if (4 * z > target) // z is too large
				break;
            
			if (z + 3 * max < target) // z is too small
				continue;
            
			if (4 * z == target) { // z is the boundary
				if (nums[i + 3] == z)
					res.add(Arrays.asList(z, z, z, z));
				break;
			}
            
            threeSum(i+1, len-1, target-z, z);
        }
        
        return new ArrayList<>(res);
    }
    
   public void threeSum(int l, int r, int target, int one) {
       if(l >= r) return;
              
       // a : 0 ~ n-3
       for(int i=l;i< len-2;i++){
           //重复的过滤掉
           if(i>l && nums[i] == nums[i-1])
               continue;
           
           if(3*nums[i] > target) break;
           
           if(nums[i] + 2*max < target) continue;
          
           int left = i+1; // 最小值
           int right = len-1; // 最大值
           
           // 如果小于0，最小值往右移；如果大于0，最大值往左移
           while(left < right){
               sum = nums[i] + nums[left] + nums[right];
           
               if(sum < target){
                   left++;
               }else if(sum > target){
                   right--;
               }else{//如果等于0，加入list中；
                   res.add(Arrays.asList(one, nums[i], nums[left], nums[right]));
                   left++;
                   right--;
                   
                   // 若接下来的几个值和nums[left]相等，抛弃，不然会重复
                   while(left < right && nums[left] == nums[left-1]){
                       left++;
                   }
                   
                   // 若接下来的几个值和nums[right]相等，抛弃，不然会重复
                   while(left < right && nums[right] == nums[right+1]){
                       right--;
                   }
               }
           }
       }       
   }
}
```