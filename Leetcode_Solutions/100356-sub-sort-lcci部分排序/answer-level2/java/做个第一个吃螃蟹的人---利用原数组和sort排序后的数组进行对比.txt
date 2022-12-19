 public int[] subSort(int[] array) {
        int [] arr = array.clone();
        int [] ans = new int[] {Integer.MAX_VALUE,-1};
        Arrays.sort(arr);
        for(int i=0;i<arr.length;i++) {
        	if(arr[i]!=array[i]) {
        		ans[0]=Math.min(ans[0], i);
        	}
        	if(arr[i]==array[i]&&ans[0]!=Integer.MAX_VALUE) {
        		ans[1]=i;
        	}
        }
        if(ans[0]==Integer.MAX_VALUE) {
        	return new int[] {-1,-1};
        }
        return ans;
    }