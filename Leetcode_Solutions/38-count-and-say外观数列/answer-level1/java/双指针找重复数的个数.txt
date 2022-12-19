### 解题思路
此处撰写解题思路
思想：双指针找重复数的个数
必须由前往后迭代，所以用countAndSay作为迭代函数，而具体的迭代过程放在change函数中：
1. 慢指针i由前往后，快指针j以慢指针为出发点，直至找到不等于慢指针相等的数；
2. 将当前找的数加入res，java中字符串操作十分方便，具体见代码

需要注意的：
1. 当快慢指针分别到达末尾位置时，需要特殊考虑一下。（若忽略会出现字符串索引越界）
当快指针到达len（因为j会自增，所以判断是否等于len）,说明此前若干个数都相同，那么返回条件是判断j == len，此时可直接return跳出循环；
若慢指针到达len-1，即末位数，则可判断这是最后一个数，返回结果也不难得到；
2. 外层循环不需要自增，因为会由x = j来赋值。

### 代码

```java
class Solution {
    public String countAndSay(int n) {
		if (n==1) return "1";
		String tem = "1";
		for (int i=1; i<n; i++) {
			tem = change(tem);
		}
		return tem;
	}
	
	public String change(String s) {
		int len = s.length();
		if (len == 1) return "11";
		int i=0;
		int j=0;
		String res = "";
		while (true) {
			i = x;
			if (i == len-1) return res+ 1 + s.charAt(i);
			j = x+1;
			while (true) {
				if (j!=len && s.charAt(i) == s.charAt(j)) {
					j++;
					continue;
				} else {
					res = res + (j-i) + s.charAt(i);
					if (j==len) return res;
					x = j;
					break;
				}
			}
		}
	}
}
```