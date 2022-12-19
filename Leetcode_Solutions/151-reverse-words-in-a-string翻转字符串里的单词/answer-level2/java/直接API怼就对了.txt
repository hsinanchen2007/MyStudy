### 解题思路
先把多的空格replace，再split，倒着放到list中，顺着取出来拼在一起(遇到空格和空字符不管，因为前面和尾巴可能还剩空格)。
### 代码

```java
class Solution {
    public String reverseWords(String s) {
		s.replaceAll(" {2,}"," ");
		LinkedList<String> list = new LinkedList<>() ;
		String[] strs = s.split(" ") ;
		for(int i=0;i<strs.length;i++) {
			if(!strs[i].equals(" ")&&(!strs[i].equals("")))
				list.addFirst(strs[i]) ;
		}
		StringBuffer ans = new StringBuffer() ;
		if(!list.isEmpty()) {
			ans.append(list.removeFirst()) ;
		}
		while(!list.isEmpty()) {
			ans.append(" ") ;
			ans.append(list.removeFirst()) ;
		}
		return new String(ans) ;
    }
}
```