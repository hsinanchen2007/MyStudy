思路：26进制转10进制，遍历字符串，由于26个字母代表的数值是1~26，所以每个字母代表的值可以用他的ASCII码值减去64得到；第一个字符是26的多少次方乘以当前字符代表的数值，可以看出是字符串的长度减一再减去当前字符的下标就是26的次方；每一个字符的结果相加就是最后的值。
```
class Solution {
    public int titleToNumber(String s) {
        //字符串的长度
    	int len = s.length();
    	int i = 0;
    	int res = 0;
    	while(i<len){
    		// 每一个字符在26个英文字母中对应的下标乘以26的（字符串位数-1-i）次方  相加
    		res+=Math.pow(26, len-1-i)*(s.charAt(i)-64);
    		i++;
    	}
    	return res;
    }
    
    public static void main(String[] args){
    	int res = new Solution().titleToNumber("ZY");
    	System.out.println(res);
    }
}
```
