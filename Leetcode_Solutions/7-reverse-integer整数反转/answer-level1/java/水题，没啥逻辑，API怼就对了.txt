### 解题思路
try catch来检测Integer parse操作的溢出。嘻嘻
### 代码

```java
class Solution {
    public int reverse(int x) {
		try {
			StringBuffer sb = new StringBuffer(String.valueOf(x)) ;
			int ans = 0 ;
			if(sb.charAt(0)=='-') {
				sb = new StringBuffer(sb.substring(1,sb.length())) ;
				sb.reverse();
				sb.insert(0,'-') ;
				ans = Integer.parseInt(new String(sb)) ;
			}else {
				sb.reverse() ;
				ans = Integer.parseInt(new String(sb)) ;
			}
			return ans ;
		}catch(Exception e) {
			return 0 ;
		}
    }
}
```