### 解题思路
此处撰写解题思路
采用滑动窗口，依次滑动，就是判断由下标i开始的字符串，最多多长无重复
### 代码

```java
class Solution {
    public int lengthOfLongestSubstring(String s) {
      Set<Character> set = new HashSet<>();
		int n = s.length();
		int i=0,j=0,ans=0;
		while(i<n&&j<n) {
			if(!set.contains(s.charAt(j))) {
				set.add(s.charAt(j++));
				ans = Math.max(ans, j-i);
			}else {
				set.remove(s.charAt(i++));
			}
		}
		return ans;
    }
}
```