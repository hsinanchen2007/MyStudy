### 解题思路
如下

### 代码

```java
class Solution {
    public int[] maxDepthAfterSplit(String seq) {
		int[]ans= new int[seq.length()];
		int index=0;
		for (char c : seq.toCharArray()) {
			ans[index++]=c=='('?(index+1&1):index&1;      
		}
		/*
		 * 题面中的depth其实就是栈的最大深度。“你需要从中选出任意一组有效括号字符串 
		 * A 和 B，使 max(depth(A), depth(B)) 的可能取值最小”。这句话其实相当于让A
		 * 字符串和B字符串的depth尽可能的接近。为什么呢？因为seq对应的栈上，每个左括号
		 * 都对应一个深度，而这个左括号，要么是A的，要么是B的。所以，
		 * 栈上的左括号只要按奇偶分配给A和B就可以啦！
		 */
    	
    	return ans;
    }
}
```