### 解题思路
哈哈！此方法笨笨的，暴力执法。
先将所有的罗马数字和其所对应的数值放在哈希表中。首先输入的罗马数字中的字符肯定是从大到小的，所以遍历该罗马数字字符串，会出现三种情况I,X,C出现在前的情况。i+1是因为此时已经算出的数是i和i+1的差。所以跳过。


### 代码

```java
class Solution {
    public int romanToInt(String s) {
     Map<Character,Integer> roMap=new HashMap<Character, Integer>();   
    roMap.put('I', 1);
	roMap.put('V', 5);
	roMap.put('X', 10);
	roMap.put('L', 50);
	roMap.put('C', 100);
	roMap.put('D', 500);
	roMap.put('M', 1000);

   		int sum = 0;
		for (int i = 0; i < s.length(); i++) {
			if (s.charAt(i) == 'I') {
				if (i + 1 < s.length() && (s.charAt(i + 1) == 'V' || s.charAt(i + 1) == 'X')) {
					sum= sum + roMap.get(s.charAt(i + 1)) - roMap.get(s.charAt(i));
					i += 1;
				} else {
					sum = sum + roMap.get(s.charAt(i));
				}
			} else if (s.charAt(i) == 'X') {
				if (i + 1 < s.length() && (s.charAt(i + 1) == 'L' || s.charAt(i + 1) == 'C')) {
					sum =sum+ roMap.get(s.charAt(i + 1)) - roMap.get(s.charAt(i));
					i += 1;
				} else {
					sum = sum+ roMap.get(s.charAt(i));
				}
			} else if (s.charAt(i) == 'C') {
				if (i + 1 < s.length() && (s.charAt(i + 1) == 'D' || s.charAt(i + 1) == 'M')) {
					sum = sum + roMap.get(s.charAt(i + 1)) - roMap.get(s.charAt(i));
					i += 1;
				} else {
					sum = sum + roMap.get(s.charAt(i));
				}
			}else {
				sum = sum + roMap.get(s.charAt(i));
			}
		}
    return sum;
    }
}
```