    public int hammingDistance(int x, int y) {
		int flag=0;
		int [] first=change(x);
		int [] second=change(y);
		for (int i=0;i<=31;i++){
			if (first[i]!=second[i]){
				flag++;
			}
		}
		return flag;
	}
	public static int[] change(int n){
		int[] nums=new int[32];
		for(int i=31;i>=0;i--){
			nums[31-i]=(n >>> i & 1);
		}
		return nums;
	}