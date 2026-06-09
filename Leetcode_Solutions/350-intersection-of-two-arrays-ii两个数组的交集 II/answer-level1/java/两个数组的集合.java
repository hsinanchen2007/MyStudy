### 解题思路
首先这个遍历方式需要按照以下这个形式写，因为我们的需要时每个值只要使用一次，如果判断两个值相等，下标自动往下走，这个很关键。另外，不能直接用一个数组来储存下来相等的信息，为什么呢？因为我们不知道这个数组要多大，不能初始化出这个数组

### 代码

```java
class Solution {
    public int[] intersect(int[] nums1, int[] nums2) {

	 	Arrays.sort(nums1);
		Arrays.sort(nums2);
		int i = 0;
		int j = 0;
		List list = new ArrayList<>(nums1.length);
		while (i < nums1.length && j < nums2.length) {
			if (nums1[i] == nums2[j]) {  //如果判断两个值相等，下标自动往下走
				list.add(nums1[i]);
				i++;
				j++;
			} else if (nums1[i] > nums2[j]) {
				j++;
			} else {
				i++;
			}
		}
		// 对象转数组
		Object[] a = list.toArray();
		int n = 0;
		int[] ans = new int[a.length];
		for (Object e: a) {
			ans[n++] = (int) e;
		}
		return ans;
	}
}
```