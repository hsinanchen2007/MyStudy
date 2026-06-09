class Solution {
    public boolean detectCapitalUse(String word) {
        boolean is=false;
        int length=word.length();
        int upper=0;
        for (int i = 0; i < length; i++) {
			if (Character.isUpperCase(word.charAt(i))) {
				upper++;
			}
		}
        if (upper==0 || upper ==length || (upper==1) && Character.isUpperCase(word.charAt(0))) {
			is=true;
		}
        return is;
    }
}