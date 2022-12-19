class Solution {
    public boolean canPermutePalindrome(String s) {
		StringBuffer sb = new StringBuffer(s);
		int count = 0;
		for(int i=sb.length()-1;i>=0;i--) {
			if(sb.charAt(i) == ' ') {
				continue;
			}else if(sb.indexOf(String.valueOf(sb.charAt(i))) == i) {
				count = count + 1;
				if(count > 1) {
					return false;
				}
			}else {
				sb.replace(sb.indexOf(String.valueOf(sb.charAt(i))), sb.indexOf(String.valueOf(sb.charAt(i)))+1, " ");
			}
		}
		return true;
    }
}