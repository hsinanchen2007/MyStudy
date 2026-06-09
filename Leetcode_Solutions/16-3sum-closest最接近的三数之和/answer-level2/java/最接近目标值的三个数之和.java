当看到这个题的时候感觉毫无头绪，转念一想，一个数组给我我只能定着一个数之后再动态遍历，所以毫不犹豫好像只能用双指针，每次只能做一个指针的变动，并且肯定是有条件的，做出来之后也就是这个样子：
```
    Arrays.sort(nums);
		int sort = nums[0] + nums[1] +nums[2]; 
		int sum;
		int start;
		int end;
		for(int i=0;i<nums.length-1;i++) {
			start = i+1;
			end = nums.length -1;
			while(start<end) {
				sum = nums[i] + nums[start] + nums[end];
				if(Math.abs(target-sum)<Math.abs(target-sort)) {
					sort = sum;
				}
				if(sum>target) {
					end--;
				}else if(sum<target) {
					start++;
				}else {
					return sort;
				}
			}
		}
		return sort;
```

运行之后显示用了十毫秒，战胜了百分之四十的人，感觉我已经想不起来更好的解决办法了但是排名还是很低我就去看了看其他的题解发现思路差不多：
```
Arrays.sort(nums);
	        int ans = nums[0] + nums[1] + nums[2];
	        for(int i=0;i<nums.length;i++) {
	            int start = i+1, end = nums.length - 1;
	            while(start < end) {
	                int sum = nums[start] + nums[end] + nums[i];
	                if(Math.abs(target - sum) < Math.abs(target - ans))
	                    ans = sum;
	                if(sum > target)
	                    end--;
	                else if(sum < target)
	                    start++;
	                else
	                    return ans;
	            }
	        }
	        return ans;
```
虽然差不多但是如果按照他的方法提交就能够击败百分之九十的，但是我自己的方法的内存消耗比他小了1m不多，所以说感觉还是能不定义变量还是不定义吧；