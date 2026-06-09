```java
public class Solution{
    /*
	 * 双指针：i指向开头，j指向末尾，交换i和j指向的元素
	 */
	public static void reverseString(char[] s) {
		int i = 0; //指向数组开头
		int j = s.length-1; //指向数组末尾
		while(i < j) {
			//交换
			char temp = s[i];
			s[i] = s[j];
			s[j] = temp;
			
			i++;
			j--;
		}
	}
```