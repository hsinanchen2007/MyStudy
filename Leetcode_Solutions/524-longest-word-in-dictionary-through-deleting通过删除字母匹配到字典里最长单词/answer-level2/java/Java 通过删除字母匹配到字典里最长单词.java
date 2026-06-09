### 解题思路
思路清晰，不过执行用时内存消耗都很高
1.在与给定字符串匹配的前提下，长度越长、字典顺序越小的字符串优先级最高，按照此条件对List进行排序。
2.排序后，依次遍历List中的字符串，题目转化为给定字符串a、b，如何判断a能否通过删除某些字符得到b的问题。

### 代码

```java
class Solution {
	class stringComparator implements Comparator<String>{
		@Override
		public int compare(String s1, String s2) {
			if(s1.length() == s2.length()) {
				return s1.compareTo(s2) ;
			}
			return s2.length() - s1.length() ;
		}		
	}
    public String findLongestWord(String s, List<String> d) {
        Collections.sort(d,new stringComparator());
    	int n = s.length() ;
    	for(String t:d) {
    		int j = 0 , m = t.length() ;
    		for(int i = 0 ; i < n && j < m; i++) {
    			if(t.charAt(j) == s.charAt(i)) {
    				j++ ;
    			}
    		}
    		if(j == m) {
    			return t ;
    		}
    	}
    	
    	return "" ;      
    }
}
```