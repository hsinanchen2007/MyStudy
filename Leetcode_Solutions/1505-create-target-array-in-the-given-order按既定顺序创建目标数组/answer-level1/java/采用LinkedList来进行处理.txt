### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int[] createTargetArray(int[] nums, int[] index) {
if (nums.length < 1 || index.length < 1 || nums.length != index.length) {
			return null;
		}
		int[] target = new int[nums.length];
		LinkedList<Integer> res = new LinkedList<>();
		for(int i = 0; i < nums.length; i++) {
			res.add(index[i], nums[i]);
		}
		for(int i = 0; i < target.length; i++) {
			target[i] = res.get(i);
			//System.out.print(target[i]+" ");
		}
		return target;
    }
}
```