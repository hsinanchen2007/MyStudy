```
/**12.整数转罗马数字（Java）*/
public String T12(int num) {
	//力扣题库系统上限9999
	if (num > 9999) return "";
	//力扣题目描述没给9000、5000的罗马字符，我自己破解出来了
	int[] nums = {9000, 5000, 1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
	String[] romans = {"M*","*","M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
	StringBuilder stringBuilder = new StringBuilder();
	for (int i = 0; i < 15; i++) {
		while (num >= nums[i]) {
			stringBuilder.append(romans[i]);
			//罗马数字本质上就是个加法操作，把高位从低位依次枚举出来即可
			num -= nums[i];
		}
	}
	return stringBuilder.toString();
}
```
```
/**12.整数转罗马数字(JavaScript)*/
function T12(num) {
	//力扣题库系统上限9999
	if (num > 9999) return '';
	//力扣题目描述没给9000、5000的罗马字符，我自己破解出来了
	var nums = [9000, 5000, 1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1];
	var romans = ['M*','*','M', 'CM', 'D', 'CD', 'C', 'XC', 'L', 'XL', 'X', 'IX', 'V', 'IV', 'I'];
	var numText = '';
	for (var i = 0; i < 15; i++) {
		while (num >= nums[i]) {
			numText += romans[i];
			//罗马数字本质上就是个加法操作，把高位从低位依次枚举出来即可
			num -= nums[i];
		}
	}
	return numText;
}
```



![1.png](https://pic.leetcode-cn.com/b5e2dc1ce47de5f75bf40661c0c51c8df40c7a2da0777aada38303ed46d0a57d-1.png)
![2.png](https://pic.leetcode-cn.com/3e684c7b973466971ddd5fc07fcd0cbb35d4bad46a4f798a42e7c4d31c563d6c-2.png)
