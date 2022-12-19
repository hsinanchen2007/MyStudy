### 解题思路
不用每次都算出来，只需要算出上一步能不能被5整出，如果不能则记录余数，再进行下一步。

### 代码

```java
class Solution {
	public List<Boolean> prefixesDivBy5(int[] A) {
		List<Boolean> ans=new ArrayList<>();
		int end=0;
		for(int n:A) {
			end=(end*2+n)%5;
			if(end==0||end==5) ans.add(true);
			else ans.add(false);
		}
		return ans;
	}
}
```