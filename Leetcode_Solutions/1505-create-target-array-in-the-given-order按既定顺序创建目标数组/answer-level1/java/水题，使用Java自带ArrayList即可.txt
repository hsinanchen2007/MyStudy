执行用时 :4 ms, 在所有 Java 提交中击败了100.00%的用户
内存消耗 :37.9 MB, 在所有 Java 提交中击败了100.00%的用户
### 解题思路
水题，使用Java自带ArrayList即可，你也可以自己写数组位移实现。
### 代码

```java
class Solution {
    public int[] createTargetArray(int[] nums, int[] index) {
		ArrayList<Integer> list = new ArrayList<>() ;
		for(int i=0;i<index.length;i++) {
			list.add(index[i],nums[i]) ;
		}
		return list.stream().mapToInt(Integer::valueOf).toArray(); 
	}
}
```