### 解题思路
由于给定的 num 类型为 int，其值不会超过 Integer.MAX_VALUE(2147483647)，num 长度最大值为 10，最小值为 1。
此时可以对 num 进行分解，以样例中的 "1234567891" 为例，长度为 10：
```
		1 		234 		567 		891	—————长度分水岭：4，7，10
    	    (Billion)	     (Million)      (Thousand)			————对应的单位
```
此时可以看出，除了 **十亿位的1** 以外，每个部分的长度均为 0 - 3，可以实现一个**处理三位数转化为英文的函数** calculate()，再加上**对应的单位**即可。
其中，0 为特殊情况，单独返回一个 Zero，即成功解得。

**处理过程中要注意的情况：**
1. 10 ~ 19的英文组成和 20 ~ 99 不同，要单独处理；
2. 分出来的部分可能有存在全部为 0 的情况，须特殊处理（先导 0 calculate() 函数会处理）

### 代码

```java
class Solution {
    public String numberToWords(int num) {
        if(num == 0) return "Zero";
        String n = String.valueOf(num);
		String ans = "";
		if(n.length() == 10) {
			String str = n.charAt(0) + "";
			ans = " " + ans + calculate(str) + " Billion";
			n = "" + n.substring(1,n.length()); /* 将处理过的部分去掉 */
		}
		if(n.length() >= 7) {
			String str = n.substring(0,n.length() - 6);
            		if(check(str) == false) ans = " " + ans + calculate(str) + " Million";
			n = "" + n.substring(str.length(),n.length()); /* 将处理过的部分去掉 */
		}
		if(n.length() >= 4) {
			String str = n.substring(0,n.length() - 3);
			if(check(str) == false) ans = " " + ans + calculate(str) + " Thousand";
			n = "" + n.substring(str.length(),n.length()); /* 将处理过的部分去掉 */
		}
		ans = ans + calculate(n);
		return ans.trim();
    }

    private static String calculate(String str) { /* 专门处理三位数 ( •̀ ω •́ )y */
		String res = "";
        	if(str.charAt(0) == '0' && str.charAt(1) != '0') str = str.substring(1,3); 
        	else if(str.charAt(0) == '0' && str.charAt(1) == '0') str = str.substring(2,3);
		/* 上面两步用于去掉先导 0 */
		if(str.length() == 3) {
			res = calculate(str.charAt(0) + "") + " Hundred";
			str = str.substring(1,3);
		}
		if(str.length() == 2) {
			if(Integer.parseInt(str) >= 10 && Integer.parseInt(str) <= 19) {
				switch(str) {
				case "10":res = res + " Ten";break;
				case "11":res = res + " Eleven";break;
				case "12":res = res + " Twelve";break;
				case "13":res = res + " Thirteen";break;
				case "14":res = res + " Fourteen";break;
				case "15":res = res + " Fifteen";break;
				case "16":res = res + " Sixteen";break;
				case "17":res = res + " Seventeen";break;
				case "18":res = res + " Eighteen";break;
				case "19":res = res + " Nineteen";break;
				}
				return res;
			}
			else {
				switch(str.charAt(0)) {
				case '0':break;
				case '1':break;
				case '2':res = res + " Twenty";break; 
				case '3':res = res + " Thirty";break;
				case '4':res = res + " Forty";break; 
				case '5':res = res + " Fifty";break;
				case '6':res = res + " Sixty";break;
				case '7':res = res + " Seventy";break;
				case '8':res = res + " Eighty";break; 
				case '9':res = res + " Ninety";break;
				}
				switch(str.charAt(1)) {
				case '0':break;
				case '1':res = res + " One";break;
				case '2':res = res + " Two";break;
				case '3':res = res + " Three";break;
				case '4':res = res + " Four";break;
				case '5':res = res + " Five";break;
				case '6':res = res + " Six";break;
				case '7':res = res + " Seven";break;
				case '8':res = res + " Eight";break;
				case '9':res = res + " Nine";break;
				}
			}
		}
		if(str.length() == 1) {
			switch(str.charAt(0)) {
			case '0':break;
			case '1':res = res + " One";break;
			case '2':res = res + " Two";break;
			case '3':res = res + " Three";break;
			case '4':res = res + " Four";break;
			case '5':res = res + " Five";break;
			case '6':res = res + " Six";break;
			case '7':res = res + " Seven";break;
			case '8':res = res + " Eight";break;
			case '9':res = res + " Nine";break;
			}
		}
		return res;
	}	

    private static boolean check(String n) { /* 判断该部分是否全是0 ( •̀ ω •́ )y */
        for(int i = 0;i < n.length();i++) {
            if(n.charAt(i) != '0') return false;
        }
        return true;
    }
}
```

希望能提供一种思路。如果有什么可以改进或者出现错误的地方，欢迎各位大佬批评指正。