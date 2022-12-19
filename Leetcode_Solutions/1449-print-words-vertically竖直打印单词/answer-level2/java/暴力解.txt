### 暴力解
暴力求解，简单直接。先确定数组中最长字符串长度作为集合size，然后循环拼接，去掉末尾空格，并放入集合中。

### 代码

```java
class Solution {
    public List<String> printVertically(String s) {
    	List<String> list = new ArrayList<>();
    	int max = Integer.MIN_VALUE;
    	String[] sa = s.split(" ");
    	for(String str : sa) {
    		max = Math.max(max, str.length());
    	}
    	for(int i=0;i<max;i++) {
    		StringBuffer sb = new StringBuffer();
    		for(String str : sa) {
    			if(str.length()-1<i) {
    				sb.append(" ");
    			}else {
    				sb.append(str.charAt(i));
    			}
    		}
    		String res = sb.toString();
    		for(int j=res.length()-1;j>=0;j--) {
    			if(res.charAt(j)!=' ') {
    				res = res.substring(0,j+1);
    				break;
    			}
    		}
    		list.add(res);
    	}
    	return list;
    }
}
```