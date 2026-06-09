class Solution {
    public int[][] findContinuousSequence(int target) {
        List<int[]> list =new ArrayList<int[]>();
    	int right = 1;
    	int left = 2;
    	int sum = right+left;
    	while(right<target&&left<target) {
    		if(sum<target) {
    			left++;
    			sum+=left;
    		}else if(sum>target) {
    			sum-=right;
    			right++;
    		}else {
    			int[] arr = new int [left-right+1];
    			int j = right;
    			for(int i=0;i<arr.length;i++,j++) {
    				arr[i]=j;
    			}
    			list.add(arr);
    			sum-=right;
    			right++;
    		}
    	}
    	int [][] ans = new int [list.size()][];
    	return list.toArray(ans);
}
}