### 解题思路
f(s) = f(s-1)(当一位有效)   + f(s-2)(当两位有效)
其实和走楼梯的方式一样，只是这里要判断走一位还是走两步是否有效

### 代码

```java
class Solution {
    public   int numDecodings(String s) {
		
		  if(s == null || s.length() == 0 ) {
			  return 0;
		  }  
		  int len = s.length();
		  int[] dp = new int[len + 1];
		  //这个是数字
		  char[] chars = s.toCharArray();
		  Map< String ,Integer> map = new HashMap< String ,Integer>();
		  for(int i = 1 ; i <= 26 ; i ++ ) {
			  map.put( String.valueOf( i) ,1);
		  }
		  
		  dp[0] = 1;
		  for(int i = 1 ; i <= len ;  i ++ ) {
			  //当前字符
			  String  curCharStr= String.valueOf(chars[i-1]);
			  //当前字符是否有编码
			  int  curNum = map.getOrDefault(curCharStr, 0);
			  int twoNum = 0;
			  if(i >= 2) {
				  //当有两个字符时
				  String  preCharStr= String.valueOf(chars[i-2]);
				  twoNum = map.getOrDefault(preCharStr + curCharStr, 0);
				  dp[i] = (curNum ==1 ? dp[i-1] :0)  + (twoNum ==1 ? dp[i-2] :0);
			  }else {
				  //第一个字符时，是否有效
				  dp[i] = (curNum ==1 ? dp[i-1] :0) ;
			  }
			
		  }

		
		  return dp[len];
	    }
}
```