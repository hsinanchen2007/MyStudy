class Solution {
public String gcdOfStrings(String str1, String str2) {
        if(!(str1+str2).equals(str2+str1)) {
        	return "";
        }
        return str1.substring(0, a(str1.length(),str2.length()));
    }

	private int a(int length, int length2) {
		// TODO Auto-generated method stub
		return length==0?length2:a(length2%length,length);
	}
}