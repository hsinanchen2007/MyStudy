```java
public class Solutin{
	/*
	 * 双指针：
	 * 	i指向数组开头，j指向数组的末尾；
	 * 	如果是元音字母，就相对应的交换，否则再移动一位。
	 * 使用List存储元音
	 */
	public static String reverseVowelsList(String s) {
		//创建存储元音的ArrayList，不区分大小写
		List<Character> vowels = new ArrayList<>();
		vowels.add('a');
		vowels.add('e');
		vowels.add('i');
		vowels.add('o');
		vowels.add('u');
		vowels.add('A');
		vowels.add('E');
		vowels.add('I');
		vowels.add('O');
		vowels.add('U');
		
		char[] chs = s.toCharArray();
		int i = 0; //指向数组开头
		int j = chs.length-1; //指向数组的末尾
		while(i <= j) {
			if(vowels.contains(chs[i]) && vowels.contains(chs[j])) {
				//i和j指向的都是元音字母
				char temp = chs[i];
				chs[i] = chs[j];
				chs[j] = temp;
				i++;
				j--;
			}else if(!vowels.contains(chs[i]) && vowels.contains(chs[j])) {
				//i指向的不是元音字母，j指向的是元音字母
				i++;
			}else if(vowels.contains(chs[i]) && !vowels.contains(chs[j])) {
				//i指向的是元音字母，j指向的不是元音字母
				j--;
			}else {
				//i和j指向的都不是原因字母
				i++;
				j--;
			}
		}
		return new String(chs);
	}
	
	
	/*
	 * 双指针：
	 * 	i指向数组开头，j指向数组的末尾；
	 * 	如果是元音字母，就相对应的交换，否则再移动一位。
	 * 使用String存储元音
	 */
	public static String reverseVowels(String s) {
		char[] chs = s.toCharArray();
		int i = 0; //指向数组开头
		int j = chs.length-1; //指向数组的末尾
		while(i <= j) {
			if(isVowel(chs[i]) && isVowel(chs[j])) {
				//i和j指向的都是元音字母
				char temp = chs[i];
				chs[i] = chs[j];
				chs[j] = temp;
				i++;
				j--;
			}else if(!isVowel(chs[i]) && isVowel(chs[j])) {
				//i指向的不是元音字母，j指向的是元音字母
				i++;
			}else if(isVowel(chs[i]) && !isVowel(chs[j])) {
				//i指向的是元音字母，j指向的不是元音字母
				j--;
			}else {
				//i和j指向的都不是原因字母
				i++;
				j--;
			}
		}
		return new String(chs);
	}
	
	/*
	 * 判断是否是元音字母
	 */
	private static boolean isVowel(char c) {
		String s = String.valueOf(c);
		String vowels = "aeiouAEIOU"; //不区分大小写
		if(vowels.lastIndexOf(s) != -1) {  //如果不存在，String.lastIndexOf(s)返回-1
			return true;
		}else {
			return false;
		}
	}
}
```