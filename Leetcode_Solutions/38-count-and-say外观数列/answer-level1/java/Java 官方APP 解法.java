### 解题思路

countAndSay函数

变量无非 count 和 say

### 代码

```java
class Solution {
    public String countAndSay(int n) {
        StringBuilder pre = new StringBuilder();
		StringBuilder curr = new StringBuilder("1");
		int count;
		char say;
		for(int i=1;i<n;i++) {
			pre = curr;
			curr = new StringBuilder();
			count = 1;
			say = pre.charAt(0);
			for(int j=1;j<pre.length();j++) {
				if(pre.charAt(j)!=say) {
					curr.append(count).append(say);
					count=1;
					say = pre.charAt(j);
				}else {
					count++;
				}		
			}
			curr.append(count).append(say);	
		}
		return curr.toString();
    }
}
```