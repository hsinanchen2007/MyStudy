### 解题思路
 看代码注释

### 代码

```java
class Solution {
    public int longestPalindrome(String s) {
            Map<Character, Integer> map=new HashMap<Character, Integer>();
	    	for(char c:s.toCharArray()) {
	    		map.put(c, map.getOrDefault(c, 0)+1);
	    	}
	    	//开始计算回文数
	    	int counts=0;
	    	for(Character c:map.keySet()) {
	    		int count=map.get(c);
	    		if(count%2==0)
	    			counts+=count;
	    		//奇数个字符串
				else
	    			counts+=count-1;
	    	}
	    	
	    	//如果小于字符串长度，说明必定含有奇数个相同字符
	    	return counts<s.length()?counts+1:counts;
    }
}
```