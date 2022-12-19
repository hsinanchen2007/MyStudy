### 解题思路
这道题不要想太复杂，我的思路是将字符串中的每一个字符都给他赋予一个整型值，然后最后将这些值累加起来就好了。
首先定义一个结果 int ans=0;
遍历一遍整个字符串，只需考虑如下情况：
	当当前字符为M且左边一个字符为C时，此时的ans加上800（即当左边的字符为C的时候，当前字符的赋值为800） 
	当当前字符为M且左边一个字符不为C时，此时ans加上1000（此情况下，当前字符的赋值为800）
	当前字符为V,X时考虑左边是否为I
	当前字符为L,C时考虑左边是否为X
	当前字符为D,M时考虑左边是否为C
	当前字符为I时，不考虑左边情况，该字符的值为1
	每次遍历都将当前字符的值加到ans里；
赋值规则：
	当前字符的左边字符并不是对应的那个字符的时候，此字符的值为其本身的值，否则，该字符的值为字符本身的值减去前一个字符本身代表的值的2倍
	例如：输入的字符串为"XIV"
		第一次：当前字符为X 且左边字符并不是I 那么该字符X的值为X本身代表的值=10，所以ans+=10
		第二次：当前字符为I ，I的值赋为1，ans+=1
		第三次：当前字符为V，且左边字符为I，那么该字符V的赋值应该为 V-2*I=3，ans+=3
	程序结束；
	注意：v-2*I式子中所有字符的值均为罗马值对应表中代表的值，而不是我们程序中为他赋予的值。


### 代码

```java
class Solution {
    public int romanToInt(String s) {
        if (s.isEmpty() || s == null)
			return 0;
		char[] charArr = s.toCharArray();
		int ans = 0;
		int bit = 1;
		for (int i = 0; i < charArr.length; i++) {
			char curr = charArr[i];
			char last = ' ';
			char next = ' ';
			if (i != 0)
				last = charArr[i - 1];
			if (curr == 'M' && last != 'C') {
				ans += 1000;
			} else if (curr == 'M' && last == 'C') {
				ans += 800;
			} else if (curr == 'C' && last != 'X') {
				ans += 100;
			} else if (curr == 'C' && last == 'X') {
				ans += 80;
			} else if (curr == 'L' && last != 'X') {
				ans += 50;
			} else if (curr == 'L' && last == 'X') {
				ans += 30;
			} else if (curr == 'D' && last != 'C') {
				ans += 500;
			} else if (curr == 'D' && last == 'C') {
				ans += 300;
			} else if (curr == 'X' && last != 'I') {
				ans += 10;
			} else if (curr == 'X' && last == 'I') {
				ans += 8;
			} else if (curr == 'V' && last != 'I') {
				ans += 5;
			} else if (curr == 'V' && last == 'I') {
				ans += 3;
			} else if (curr == 'I')
				ans++;
		}
		return ans;
    }
}
```