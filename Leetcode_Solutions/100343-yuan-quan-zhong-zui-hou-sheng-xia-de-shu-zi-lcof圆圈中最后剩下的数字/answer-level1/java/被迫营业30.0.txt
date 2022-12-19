class Solution {
    public int lastRemaining(int n, int m) {
StringBuffer sb = new StringBuffer();
    	for(int i=0;i<n;i++) {
    		sb.append(i);
    	}
    	int j=0;
    	while(sb.length()>=2) {
    		j =(j+m-1)%sb.length();
    		sb.deleteCharAt(j);
    	}
    	return Integer.valueOf(sb.toString());
    }
}