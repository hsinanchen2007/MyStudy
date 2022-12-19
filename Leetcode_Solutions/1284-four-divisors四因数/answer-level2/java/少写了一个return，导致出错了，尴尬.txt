class Solution {
    public static int sumFourDivisors(int[] nums) {
		int count=0;
		for(int i=0;i<nums.length;i++) {
			count+=cal(nums[i]);
		}
		
		return count;
    }
	
	public static int cal(int n) {
		int res=0;
		if(cal1(n)==1) {
			return res;
		}else {
			for(int i=2;i*i<n;i++) {
				if(cal1(i)==1&&n%i==0) {
                    if(n==i*i*i){
                        res=1+n+i+n/i;
                        return res;
                    }else if(cal1(n/i)==1) {
						res=1+n+i+n/i;
						return res;
					}
                    return res;
				}
			}
			return res;
		}
	}
	public static int cal1(int n) {
		if(n==2||n==3) {
			return 1;
		}else {
			if((n+1)%6==0||(n-1)%6==0) {
				for(int i=1;(6*i-1)*(6*i-1)<=n;i++) {
					if(n%(6*i-1)==0||n%(6*i+1)==0) {
						return 0;
					}
				}
				return 1;
			}
		}
		return 0;
	}
}