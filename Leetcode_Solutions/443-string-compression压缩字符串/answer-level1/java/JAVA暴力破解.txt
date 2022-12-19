在所有 Java 提交中击败了84.74%的用户

class Solution {
    public static int compress(char[] chars) {
		int i,j,cur; 
        i = j = cur = 0;
		char pre = chars[i] ;
        while(j <= chars.length) {
        	if(j == chars.length || pre != chars[j]) {
				chars[cur++] = pre;
				char ar[] = String.valueOf(j - i).toCharArray();
				i = j;
				pre = j == chars.length? chars[j-1] : chars[j];
        		for (int k = 0; !(ar.length == 1 && ar[0] == '1') && k < ar.length; k++) {
					chars[cur++] = ar[k];
				}
			}
        	j++;
        }
        return cur;
    }
}