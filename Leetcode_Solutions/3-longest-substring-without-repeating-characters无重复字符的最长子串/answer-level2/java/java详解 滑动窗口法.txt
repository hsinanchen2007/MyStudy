# 解题思路
- 设置标签start和end初始位置等于0
- start用于记录当前子串的初始位置
- 建立一个256位大小的整型数组 freq ，初始化全为0，用来建立字符和其出现位置之间的映射。
- 利用end自增遍历一遍整个字符串 循环条件为end小于字符串长度
	    - freq[s.charAt(end)] = ++end    end+1的值即为当前字符对应字符串中的绝对位置
        - 每次进入循环首先判断，若freq[s.charAt(end)]中的值大于start的值时，我们认为在当前子串中，已经含有重复的字符，即在start位置之后已经出现            过该字符，此时就将start位置移动至重复字符的位置，例如对于abca，遍历到第二个字母a时，就将原来的start=0，移动到start=1，从上一个a之后开始计算子字符串；若不大于start值，则即使该字符出现过，但也并不在当前所计算的子字符串内，直接继续前进遍历字符串。

![WHJJWX\]R_UC4@`{MZWS9@DK.png](https://pic.leetcode-cn.com/b52b544d02b8f69961904e609d3262ee1c8c5910b64afd10e6705401edabe368-WHJJWX%5DR_UC4@%60%7BMZWS9@DK.png)

时间复杂度：O(n)

# 代码
```
class Solution {
    public int lengthOfLongestSubstring(String s) {
        int max = 0;
        int start = 0;
        int end = 0;
        int[] freq = new int[256];
		while(end<s.length()) {
			if(freq[s.charAt(end)]>start) {
				start = freq[s.charAt(end)];
			}
			freq[s.charAt(end)] = ++end;
			if(max<end-start) {
				max = end-start;
			}
		}
		return max;
    }
}
```
