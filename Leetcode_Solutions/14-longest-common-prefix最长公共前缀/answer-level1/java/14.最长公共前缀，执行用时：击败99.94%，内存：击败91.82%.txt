
题目分析：题目是要找出一个最长公共前缀，所以这个最长公会前缀的length()的最大值是字符串数组中最短的那个字符串minString；且这个前缀一定是某个字符串的前几个字母。而不存在的情况有很多，排除一些特殊情况可以有效减少代码运行时间。

思路：  
    1. 找出minString
    2. 排除特殊情况：
                    1、字符串数组为空，返回 null
                    2、字符串数组长度为1，直接返回 strs[0]
                    3、字符串数组中存在空字符串 返回 null
                    4、数组中存在一个单词的首字母与其他单词的首字母不同，返回 null
    3. 双层for循环找出 最长公共前缀
    4. 注意，在内层for循环比较之前，可以再排除一种情况：如果strs[i] 与 minString 值相同，则不执行内层循环。以减少代码运行时间。
```
static String longestCommonPrefix(String[] strs) {
    	if (strs.length == 0) {
			return "";
		}
    	if (strs.length == 1) {
			return strs[0];
		}
    	String min = strs[0] ;
        for (int i = 0; i < strs.length; i++) {
        	if (strs[i].isEmpty()) {
				return "";
			}
        	if (strs[0].charAt(0) != strs[i].charAt(0)) {
				return "";
			}
        	if (strs[i].length() <= min.length()) {
				min = strs[i];
        	}
        }
        for (int i = 0; i < strs.length; i++) {
        	if (min.equals(strs[i])) {
				continue;
			}
	        for (int j = min.length()-1; j > 0 ; j--) {
				if (min.charAt(j) != strs[i].charAt(j)) {
					min = min.substring(0, j);
				}
			}
		}
        return min;
    }
```
