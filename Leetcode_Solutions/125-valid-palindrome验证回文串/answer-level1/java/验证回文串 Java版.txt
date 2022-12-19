```java
public class Solution{
	/*
	 * 正则表达式：
	 * \w 表示字母和数字
	 * ^ 表示非、除了
	 * ^\w 表示除了字母和数字
	 */
	public static boolean isPalindromeRegEx(String s) {
		String regEx = "[^a-z0-9A-Z]"; //除了字母和数字
		Pattern p = Pattern.compile(regEx);
		Matcher m = p.matcher(s);
		String str = m.replaceAll("").trim().toLowerCase(); //将字母变小写
//		System.out.println(str);
		
		int i = 0; //指向字符串开头
		int j = str.length()-1; //指向字符串结尾
		while(i <= j) {
			if(str.charAt(i) == str.charAt(j)) {  //如果首尾字符一样，则继续比下一组
				i++;
				j--;
			}else {  //否则直接返回false
				return false;
			}
		}
		return true; //除了字母和数字
		Pattern p = Pattern.compile(regEx);
		Matcher m = p.matcher(s);
		String str = m.replaceAll("").trim().toLowerCase(); //将字母变小写
//		System.out.println(str);
		
		int i = 0; //指向字符串开头
		int j = str.length()-1; //指向字符串结尾
		while(i <= j) {
			if(str.charAt(i) == str.charAt(j)) {  //如果首尾字符一样，则继续比下一组
				i++;
				j--;
			}else {  //否则直接返回false
				return false;
			}
		}
		return true;
	}

	/*
	 * 双指针：i指向字符串开头，j指向字符串结尾
	 * 	现判断当前元素是否是数字和字母，如果是的话就比较；
	 * 	如果至少有一个不是，则跳过不满足条件的元素继续比较。
	 */
	public static boolean isPalindromeComplex(String s) {
		String str = s.toLowerCase(); //将字符串中的字母都变为小写
		int i = 0;  //指向字符串开头
		int j = str.length()-1; // 指向字符串尾部
		while(i <= j) {
			//如果两字符都是字母或数字
			if(isCharAndNum(str.charAt(i)) && isCharAndNum(str.charAt(j))) {
				if(str.charAt(i) == (str.charAt(j))) { //如果两字符相同
					i++;
					j--;
				}else {
					return false;
				}
			}else if(!isCharAndNum(str.charAt(i)) && isCharAndNum(str.charAt(j))) {
				//如果j指向的字符是字母或数字，另一个i指向的不是
				i++;
			}else if(isCharAndNum(str.charAt(i)) && !isCharAndNum(str.charAt(j))) {
				//如果i指向的字符是字母或数字，另一个j指向的不是
				j--;
			}else {
				//如果i和j指向的字符都不是字母或数字
				i++;
				j--;
			}
		}
		return true;
	}
	
	//判断字符是不是数字和字母
	public static boolean isCharAndNum(char c1) {
		if((c1 >= 48 && c1 <= 57) || (c1 >= 97 && c1 <= 122)) {
			return true;
		}
		return false;
	}
}
```