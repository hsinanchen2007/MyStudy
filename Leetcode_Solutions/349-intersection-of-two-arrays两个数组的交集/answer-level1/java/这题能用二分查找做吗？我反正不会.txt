**参考自以下题解**
[https://leetcode-cn.com/problems/intersection-of-two-arrays/solution/2ge-shu-zu-jiao-ji-by-bisonjuzi/](https://leetcode-cn.com/problems/intersection-of-two-arrays/solution/2ge-shu-zu-jiao-ji-by-bisonjuzi/)

```
	public int[] intersection(int[] nums1, int[] nums2) {
		Set<Integer> set = new HashSet<Integer>();// Set集合存放唯一不重复的值

		// 把其中一个数组的数添加到 set集合中
		for (Integer n : nums1) {
			set.add(n);
		}

		// 声明一个新的数组，大小由个数最少的数组决定
		int leng = Math.min(nums1.length, nums2.length);
		int[] result = new int[leng];

		// 声明一个变量，记录相同的个数
		int i = 0;
		for (Integer n : nums2) {
			// contains 包含,返回值类型boolean,set集合中如果包含n这个值,则为true
			if (set.contains(n)) {
				result[i++] = n;
				set.remove(n);// 移除已经包含的数，不然重复
			}
		}
		// 返回一个新的数组，copyof(复制的对象是数组,复制的长度)
		return Arrays.copyOf(result, i);
	}
```
写这道题目的时候，我想着二分查找，但是感觉行不通，会比较麻烦吧
二分查找，我的思路是，先把数组排序，然后用二分查找，但是时间和空间都会消耗很大

最终采用上面这种方法，是**参考别人的题解**所写的

*如果有用二分查找尝试过的，可以分享一下经验和结果，谢谢*