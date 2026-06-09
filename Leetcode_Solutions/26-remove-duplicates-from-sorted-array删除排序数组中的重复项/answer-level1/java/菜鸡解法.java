class Solution {
 public static int removeDuplicates(int[] nums) {
		int work=0,index=0;
		while(work<=nums.length-1){
			int similar=1;
			while(work+similar<=nums.length-1&&nums[work]==nums[work+similar]){
				similar++;
			}
			//System.out.println(similar);
			nums[index]=nums[work+similar-1];
			index++;
			work+=similar;
		}		
		return index;
    }
}
执行用时 :1 ms  99.79%
内存消耗 :41.4 MB 14.37%
