### 解题思路
如下面注释，老老实实模拟竖乘就好啦
0、1单独处理是为了避免无意义的乘法，直接是可以运行的

关键在于我们竖乘的时候是从结果的个位开始，当计算到最大一位时结束
如果我们考虑将num1、num2看作一个二维数组
例如：
num1 = 123;num2 = 34;
则：
	1	2	3
3	3	6	9
4	4	8	12
如果我们用45°斜线从右下角开始往左上角走，斜线覆盖依次为：
{12}、{9,8}、{6,4}、{3}
每个大括号可以确定一个位和一个进位，我们从结果位的个位开始处理直到最后一个大括号
12:				12
9+8:		   182
6+4:		  1182
3:			  4182
便得出了结果，解法基于这个步骤的模拟
### 代码

```java
class Solution {
public String multiply(String num1, String num2) {
		//代码可以处理0和1的，在这里加上判别是希望提高一下效率
		//用0或1去乘以110位的数字感觉好浪费啊
		if(num1.equals("0")||num2.equals("0"))
			return "0";
		if(num1.equals("1")||num2.equals("1"))
			return num1.equals("1")?num2:num1;
		int len1 = num1.length();
		int len2 = num2.length();
		int reslen = len1+len2;//两数相乘最长为两数的位数之和
		int single_multipy = 0,add = 0;
		char[] result = new char[reslen];
		for(int i=0;i<reslen;i++) 
			result[i] = '0';//java好像默认不是字符0，手动初始化一下
		for(int i=reslen-1;i>=1;i--) {//从结果的个位开始
			for(int j=Math.min(len2-1,i-1);j>=0&&(i-j-1)>=0&&(i-j-1)<len1;j--) {
				//这里的循环相当于是右下角开始斜线遍历由num1和num2组成的二维数组
				//这样循环满足竖乘运算步骤
				single_multipy = (num2.charAt(j)-'0') * (num1.charAt(i-j-1)-'0');//两个1位数乘积
				add = (result[i]-'0')+single_multipy%10;//将乘积的个位与结果当前位相加
				result[i] = (char)(add%10+'0');//和的个位放入当前位
				result[i-1] += single_multipy/10+add/10;//和的十位作为进位，只会进位一次嘛
			}
		}
		//去掉开头的0，因为有些乘出来长度可能小于两数位数之和
		return new String(result).replaceAll("^(0+)", "");
	}
}
```