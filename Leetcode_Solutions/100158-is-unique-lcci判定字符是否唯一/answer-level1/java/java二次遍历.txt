第一次遍历字符串所有字母；
第二次遍历从第一次遍历的后一位开始；
判断两次遍历的字母是否相等，一旦相等则返回false；
默认返回true；

class Solution {
    public boolean isUnique(String astr) {
        for (int i = 0; i < astr.length() - 1; i++) {
			for (int j = i + 1; j < astr.length(); j++) {
				if (astr.charAt(i) == astr.charAt(j)) {
					return false;
				}
			}
		}
		return true;
    }
}
