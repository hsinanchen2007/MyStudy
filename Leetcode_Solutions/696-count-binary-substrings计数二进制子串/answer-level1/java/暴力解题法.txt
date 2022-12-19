### 解题思路
第一个i循环从第一个遍历到倒数第二个
	里层的j循环从i后面开始遍历到最后一个寻找到与i坐标字符不同的字符
		找到了就判断这后面的长度和j与i之间的长度是否相同,一个一个遍历,直至找到不同,就跳出循环
			找不到就说明长度与j与i之间的长度相同,那么该字符串满足要求,通时...我编不下去了,我自己写的自己不知道为什么....

### 代码

```java
class Solution {
    public int countBinarySubstrings(String s) {
       int count = 0;
		for(int i = 0; i < s.length()-1; i++) {
			inner:
			for(int j = i+1; j< s.length(); j++) {
				if(s.charAt(i) != s.charAt(j)) {
					for(int k = j+1; k< j+j-i; k++) {
						if(k == s.length() || s.charAt(k)!=s.charAt(j)) {
							if(k-j>j-i) {
                                i = k;
                            }
							break inner;
						}
					}
					count++;
					break;
				}
			}
		}
		return count;
    }
}
```