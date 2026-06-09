# JAVA：
public int pivotIndex(int[] nums) {
		if(nums.length<=1)return -1;
		int ans = 0;
		for(int i=0;i<nums.length;i++)
			ans += nums[i];
		int l =0,r=ans;
		int i = 0;
		while(i<nums.length) {
			int num = nums[i];
			r-=num;
			if(l==r)return i;
			l+=num;
			i++;
		}
		return -1;
	}
# pythpn：
    def pivotIndex(self, nums) -> int:
        if(len(nums)<=1):return -1
        sum_val = sum(nums)
        l = 0;r=sum_val
        for i in range(0,len(nums)):
            num = nums[i]
            r -= num
            if l==r:
                return i
            l+=num

        return -1