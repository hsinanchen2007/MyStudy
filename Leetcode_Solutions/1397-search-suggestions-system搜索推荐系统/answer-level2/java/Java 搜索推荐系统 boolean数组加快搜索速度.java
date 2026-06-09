### 解题思路
1.将products数组按照字典序排序，对应题目要求：***"如果前缀相同的可推荐产品超过三个，请按字典序返回最小的三个"***。
2.使用substring截取searchWord前i个单词，与products中每个单词的前i个进行匹配，若相等，将单词加入结果中，如果当前结果集有了三个单词，直接返回。***如果不相等，对该单词做标记，以后不再访问***。因为如果前i个字符都不相等，后面的字符一定不相等。
3.如果products中某个字符串的长度 < searchWord.length() 那么在截取字符串的时候可能需要特殊处理。

### 代码

```java
class Solution {
	class stringComparator implements Comparator<String>{

		@Override
		public int compare(String s1, String s2) {
			return s1.compareTo(s2) ;
		}
		
	}
    List<List<String>> ans = new ArrayList<>() ;
    public List<List<String>> suggestedProducts(String[] products, String searchWord) {
		Arrays.sort(products,new stringComparator());
        if(products == null || products.length == 0) return ans ;
    	int len = searchWord.length() ;
    	int n = products.length ;
    	boolean[] isMatch = new boolean[n] ;
    	Arrays.fill(isMatch, true) ;
    	for(int i = 0 ; i < len ; i++) {
    		String temp1 = searchWord.substring(0,i+1) ;
    		List<String> temp = new ArrayList<>() ;
    		for(int j = 0 ; j < n ; j++) {
    			if(!isMatch[j]) {
    				continue ;
    			}
    			int curr_len = products[j].length() ;
    			String temp2 = "";
    			if(i < curr_len) {
    				temp2 = products[j].substring(0,i+1) ;
    			}else {
    				temp2 = products[j] ; 
    			}
    			if(temp1.equals(temp2)) {
    				temp.add(products[j]) ;
    			}else {
    				isMatch[j] = false ;
    				continue ;
    			}
    			if(temp.size() == 3) {
    				break ;
    			}
    		}
    		ans.add(new ArrayList<>(temp)) ;
    	}  	
    	return ans ;
    }
}
```