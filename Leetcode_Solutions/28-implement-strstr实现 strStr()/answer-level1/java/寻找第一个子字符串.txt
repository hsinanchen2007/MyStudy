### 解题思路
此处撰写解题思路
思想：使用双指针。
1. 初始化指针pH,pN分别指向母串与子串的首字母，外层循环：遍历母串，直到发现当前字母与子串的首字母相同；
2. 进入内层循环，循环lenN次，目的是检测母串接下来的lenN个字母是否与子串相同，若中途发现有不匹配的情况，母串指针可以+1，并break,退出内层循环，回到外层循环；
3. 若一直匹配直到循环结束，直接返回当前的pH即可；
需要注意的是：
0. 当子串为空时，返回0
1. 外层循环只需lenH-lenN次，因为再往后不必要，而且可能造成越界
2. 别忽略了内层循环中else板块的pH++，若不自增会造成无限循环（答主开始忽略了，后通过debug发现问题）
3. 最末别忘了返回-1
### 代码

```java
class Solution {
    	public int strStr(String haystack, String needle) {
		int lenH = haystack.length();
		int lenN = needle.length();
		if (lenN==0) return 0;
		int pH = 0;
		int pN = 0;
		while (pH <= lenH-lenN) {
			if (haystack.charAt(pH) == needle.charAt(pN)) {
				for (int i=0; i<lenN; i++) {
					if (haystack.charAt(pH+i) == needle.charAt(pN+i)) {
						if (i == lenN-1) return pH;
						continue;
					} else {
						pH++;
						break;
					}					
				}
			} else {
				pH++;
			}
		}
		
		return -1;
	}
}
```