### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public static int[] createTargetArray(int[] nums, int[] index) {
		 List<Integer> templist =new ArrayList<Integer>();
		 
		 for(int i=0;i<nums.length;i++) {
			 templist.add(index[i],nums[i]);
		 }
		 
		 int[] tagert =new int[templist.size()];
		 
		 for(int i=0;i<templist.size();i++) {
			 tagert[i]=templist.get(i);
		 }
		 	return tagert;
	 }
}
```