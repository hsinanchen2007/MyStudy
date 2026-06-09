class Solution {
	public static boolean isNumber(String s) {
		char tem = s.charAt(s.length() - 1);
		if (tem == 'f' || tem == 'F' || tem == 'd' || tem == 'D')
			return false;
		try {
			Double.parseDouble(s);
			System.out.println(Double.parseDouble(s));
		} catch (Exception e) {
			return false;
		}
		return true;
	}
}