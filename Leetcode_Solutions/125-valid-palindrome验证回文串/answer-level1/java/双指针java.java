字符串转小写然后双指针，写了一个函数判断当前字符是否是数字或者字母。具体看注释就可以了。
```java
public class Solution {
    public static boolean isPalindrome(String s) {
        if(s == null || s == "" || s.length() == 1) return true;
	//转小写
        s = s.toLowerCase();
	int left = 0;
	int right = s.length() - 1;
	while(left < right) {
	    //如果left指向的字符不是数字和字母
	    while((left < right) && !check(s.charAt(left)))
	        left++;
	    //如果right指向的字符不是数字和字母
	    while((left < right) && !check(s.charAt(right)))
	        right--;
	    //如果left和right都指向的字符符合条件，比较
	    if(s.charAt(left) == s.charAt(right)) {
	    //如果是相同字符，下一个
	        left++;
	        right--;
            }else {
	        //发现不同字符即返回false
		 return false;
	    }
        }  
	return true;
    }
	
    public static boolean check(char c) {
        //检测字符c是否是数字或者字母
	int b = (int) c;
	if((48 <= b && b <= 57) || (97 <= b && b <= 122)) return true;
	return false;
    }
}
```
