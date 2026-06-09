//12. 整数转罗马数字
	public String intToRoman(int num) {
		char[] dirs = {'I','V','X','L','C','D','M'};
		int[] nums = {num%10,(num%100)/10,(num%1000)/100,num/1000};
		String res = "";
		for(int i=0;i<4;i++) {
			switch (nums[i]) {
			case 4:
				res = dirs[2*i]+""+dirs[2*i+1]+res;
				break;
			case 9:
				res = dirs[2*i]+""+dirs[2*i+2]+res;
				break;
			case 5:
				res = dirs[2*i+1]+res;
				break;
			default:
				if(nums[i]<4) {
					for(int j=0;j<nums[i];j++) {
						res=dirs[2*i]+res;
					}
				}else {
					String tmp=dirs[2*i+1]+"";
					for(int j=0;j<nums[i]-5;j++) {
						tmp+=dirs[2*i];
					}
					res= tmp+res;
				} 
				break;
			}
		}
		
		return res;
	}