
class Solution {
    public void reverseString(char[] s) {
        int length = s.length;
		for (int i = 0, j = length -1; i <= j; i++, j--) {
			char temp = s[i];
			s[i] = s[j];
			s[j] = temp;
		}
    }
}
