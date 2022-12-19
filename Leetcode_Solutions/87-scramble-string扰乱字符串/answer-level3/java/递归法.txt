### 解题思路
通过递归的方式，最后的叶子节点是否和匹配串一样
 同时通过dp 记录 dp[str1] = start_end 减少树的递归，
但是要记得在中间要剪枝来优化，否则时间超时

### 代码

```java
class Solution {
  
 public   boolean isScramble(String s1, String s2) {
		 Map<String,Boolean> dp = new HashMap<String,Boolean>();
		 boolean result = match(  s1 ,   s2 ,  0 ,s1.length() - 1 ,  dp );
		 return result;
    }
	 
	 private static boolean match(String s , String targe ,int start ,int end ,Map<String,Boolean> dp ) {
		 if(start == end) {
			 boolean result = s.length() == 1 && s.charAt(0) == targe.charAt(start);
			 return result;
		 }
		 
		 String key = s + "_" + start + "_" + end;
		 
		 if(dp.containsKey(key)) {
			 return dp.get(key);
		 }
		 
		 if(s.equals( targe.substring(start, end + 1))) {
			 dp.put(key, true);
			 return true;
		 }
		 
		  // 看一下字符个数是否一致，不同直接return false
	        int n = s.length();
	        HashMap<Character, Integer> map = new HashMap<Character, Integer>();
	        for (int i = 0; i < n; i++) {
	            char c1 = s.charAt(i);
	            char c2 = targe.charAt(start + i);
	            map.put(c1, map.getOrDefault(c1, 0) + 1);
	            map.put(c2, map.getOrDefault(c2, 0) - 1);
	        }
	        for (Character key2 : map.keySet()) {
	            if (map.get(key2) != 0) {
	            	 dp.put(key, false);
	                return false;
	            }
	        }
 
		 
		 //上面不直接相等时，尝试交换
		 for(int i = 1 ; i <   s.length()   ; i ++ ) {
			 // i 是交换点
			 String tem1 = s.substring(0 ,i);
			 String tem2 = s.substring(i );
			 
			 boolean r1 = match(tem1,targe,start,start + tem1.length() -1, dp);
			 boolean r2 = match(tem2,targe,start + tem1.length(), end ,dp);
			 
			 boolean result = r1 && r2;
			 if(result) {
				 //匹配了就直接返回了
				 dp.put(key, result);
				 return result;
			 }
			 //交换
			 r1 = match(tem2,targe,start,start + tem2.length() -1  , dp);
			 r2 = match(tem1,targe, start + tem2.length()  , end ,dp);
			  result = r1 && r2;
			  if(result) {
				 //匹配了就直接返回了
				 dp.put(key, result);
				 return result;
			 }
		 }
		 //都不行，就返回false
		 dp.put(key, false);
		 return false;
	 }

}
```