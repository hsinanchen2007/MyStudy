class Solution {
    public int[] distributeCandies(int candies, int num_people) {
         int[] arr = new int[num_people];
	        Arrays.fill(arr, 0);
	        int i=0;
	        int j=1;
	        while(true) {
	        	if(i==arr.length) {
	        		i=0;
	        	}
	        	if(candies<j) {
	        		arr[i]+=candies;
	        		break;
	        	}
	        	arr[i++]+=j;
	        	candies-=j;
	        	j++;
	        }
	        return arr;
    }
}