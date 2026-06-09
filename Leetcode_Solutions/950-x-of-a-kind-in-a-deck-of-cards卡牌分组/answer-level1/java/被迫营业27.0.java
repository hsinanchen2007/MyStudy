class Solution {

        public boolean hasGroupsSizeX(int[] deck) {
		int[] arr = new int[1000];
		for(int i: deck) {
			arr[i]++;
		}
		int value =-1;
		for(int i=0;i<arr.length;i++) {
			if(arr[i]!=0) {
				if(value==-1) {
					value=arr[i];
				}else {
					value=a(value,arr[i]);
				}
			}
		}
		return value>=2;
    }

	private int a(int value, int i) {
		// TODO Auto-generated method stub
		return value==0?i:a(i%value,value);
	}
    
}