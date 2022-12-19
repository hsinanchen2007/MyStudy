class Solution {
    public int compress(char[] chars) {
        int count  = 0;
        int i=0;
		int j = 1;
		 for (;j<=chars.length;j++) {
			if(j!=chars.length&&chars[i]==chars[j]) {
				
			}else {
				chars[count++] =  chars[i];
				if(j-i>1) {
//因为 双位数 需要分开写 所以转为字符数组
					for (char c : (""+(j-i)).toCharArray()) {
						chars[count++] =c;
					}
					
				}
				
				i=j;
			}
		}
		 System.out.println(chars);
	      return count;    
    }
}