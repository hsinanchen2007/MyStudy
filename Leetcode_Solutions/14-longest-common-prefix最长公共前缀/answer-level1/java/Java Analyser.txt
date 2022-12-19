### 解题思路

不用多说，很经典，但是很容易在细节出错。

第一种解法的思想是：先指定一个字符串，不断缩短这个字符串以达到最长公共前缀的要求。

首先应该判断的就是输入的特殊情况；

返回最长公共前缀，其实也可以将字符串数组中最短的字符串求出来，然后进行判断，这样的做法对于大量的测试，或者说有这个字符串数组很大时很有用。

返回什么，就声明什么。prefix这里初始化为 strs[0]，下面代码的目的是不断缩短 prefix，一遍一遍的看是否是公共前缀，这里用到了 indexOf() 函数。 当 prefix 缩短为空串是就可以返回。

否则，碰巧 strs[0] 就是最长公共前缀，返回它即可。

```java
	public String longestCommonPrefix3(String[] strs) {
	   if (strs == null || strs.length == 0) return "";
	   String prefix = strs[0];
	   for (int i = 1; i < strs.length; i++)
	       while (strs[i].indexOf(prefix) != 0) {
	    	   prefix = prefix.substring(0, prefix.length() - 1);
	           if (prefix.isEmpty()) return "";
	       }        
	   return prefix;
	}
```

第二种解法的思想是：从前向后比，这和人的判断思路一样，每次看所有字符串同位置的一个字符，如果不相等了，就返回之前所有字符的合集。

```java
public String longestCommonPrefix(String[] strs) {
    if (strs == null || strs.length == 0) return "";
    for (int i = 0; i < strs[0].length() ; i++){
        char c = strs[0].charAt(i);
        for (int j = 1; j < strs.length; j ++) {
            if (i == strs[j].length() || strs[j].charAt(i) != c)
                return strs[0].substring(0, i);             
        }
    }
    return strs[0];
}
```

