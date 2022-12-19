### 解题思路
没有思路，干就完事儿了。

### 代码

```java
class Solution {
    public List<Integer> findDisappearedNumbers(int[] nums) {
List<Integer> list=new ArrayList<Integer>();
int [] a=new int [nums.length+1];
Arrays.parallelSort(nums);
int count=0;
for(int i:nums) {
	a[i]++;
}
for(int i=1;i<a.length;i++) {
	if(a[i]==0) list.add(i);
}
    	
    	
    	
    	return list;
    }
}
```