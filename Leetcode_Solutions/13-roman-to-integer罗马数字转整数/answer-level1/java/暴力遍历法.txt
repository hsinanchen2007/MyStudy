第一次遍历一个字符把符合值加到结果里，第二次遍历两个字符从结果中减去符合值。
```
class Solution {
    public int romanToInt(String s) {
	int result = 0;
        for(int i = 0; i < s.length(); i++) {
            switch(s.charAt(i)) {
                case 'I': 
                    result += 1;
                    break;
                case 'V': 
                    result += 5;
                    break;
                case 'X':
                    result += 10;
                    break;
                case 'L':
                    result += 50;
                    break;
                case 'C':
                    result += 100;
                    break;
                case 'D':
                    result += 500;
                    break;
                case 'M':
                    result += 1000;
                    break;
            }
        }
	for(int j = 0; j < s.length() - 1; j++) {
            switch("" + s.charAt(j) + s.charAt(j+1)) {
                case "IV":
                case "IX":
                    result -= 2;
                    break;
                case "XL":
                case "XC":
                    result -= 20;
                    break;
                case "CD":
                case "CM":
                    result -= 200;
                    break;
            }
        }
        return result;
    }
}
```