### 解题思路
使用尺寸法解决问题：
	尺取法：顾名思义，像尺子一样取一段，尺取法通常是对数组**保存一对下标**，即所选取的区间的**左右端点**，然后根据实际情况不断地**推进**区间左右**端点**以得出答案。之所以需要掌握这个技巧，是因为尺取法比直接暴力枚举区间效率高很多，尤其是数据量大的时候，所以尺取法是一种高效的枚举区间的方法，一般用于求取有一定限制的区间个数或最短的区间等等

### 代码

```java
class Solution {
    public int lengthOfLongestSubstring(String s) {
        int s_length = s.length();
		// 如果输入的字符串只有一个或者是空的字符串那么直接返回
		if (s_length<2) {
			return s_length;
		}
		int start = 0; // 尺取法的起点
		int end = 1;	// 尺取法的终点位置
		int length = 0;	// 最后返回的长度
		char ch = ' ';
		int flag = -1; // 记录重复的位置
		//
		while (end <= s_length - 1) {	
			ch = s.charAt(end);
			flag = check(s,start,end,ch);// 返回重复的位置
	
			if (flag != -1) {// 该长度start~end之间有重复
				if (length < end - start ) {// 如果重复处没有长度大于之前记录最大值修改
					length = end - start;
				}
				start = flag + 1;// start跳到重复字符的下一个，那么新的start ~ end不重复
				end++;
			}else {// 没有重复end继续往下扫描
				end++;
			}
		}
        if (length < end - start ) {// 防止最后一个为最长子串
					length = end - start ;
				}
		return length;
    }

	private static int check(String s, int i, int j, char ch) {
		for (int k = i; k < j; k++) {
			if (s.charAt(k) == ch) {
				return k;
			}
		}
		return -1;
	}
}
```