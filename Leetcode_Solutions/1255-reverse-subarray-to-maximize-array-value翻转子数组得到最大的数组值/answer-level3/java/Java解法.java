```
class Solution {
   public int maxValueAfterReverse(int[] nums) {
    	int ans=0,all=0;
    	int n=nums.length;
    	for(int i=0;i<n-1;i++)
    		all+=Math.abs(nums[i]-nums[i+1]);
    	
    	int mn=Math.max(nums[0], nums[1]);
    	int mx=Math.min(nums[0], nums[1]);
    	for(int i=1;i<n;i++) {
    		int t1=Math.min(nums[i], nums[i-1]);
    		int t2=Math.max(nums[i], nums[i-1]);
    		if(mn<t1) ans=Math.max(ans, t1-mn);
    		if(mx>t2) ans=Math.max(ans, mx-t2);
    		mn=Math.min(mn, t2);
    		mx=Math.max(mx, t1);
    	}
    	ans*=2;
    	for(int i=1;i<n;i++) {
    		ans=Math.max(ans, Math.abs(nums[i]-nums[0])-Math.abs(nums[i]-nums[i-1]));
    		ans=Math.max(ans, Math.abs(nums[n-i-1]-nums[n-1])-Math.abs(nums[n-i]-nums[n-i-1]));
    	}	
    	return all+ans;
    }
}
```
