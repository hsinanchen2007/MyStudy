**先贴提交结果图：**
![image.png](https://pic.leetcode-cn.com/f1f8a149f9c0d3b9f5738a30a03f43d6c8b6a1adea9dab30ea4729bd82a146ad-image.png)

	public static int[] maxSlidingWindow(int[] nums, int k) {
		int len = nums.length;
		if(len*k==0)return new int[0];
		int[] res;
		if (len <= k) {
			int mm= Integer.MIN_VALUE;
			for (int num : nums) {
			mm = mm < num ? num : mm;
			}
			res = new int[1];
			res[0] = mm;
			return res;
		}

		res = new int[len - k + 1];
		int curMAxIndex = Integer.MIN_VALUE;
		int i=0;
		int j=i+k-1;
		while (j<len && i<len-k+1) {
			int max = Integer.MIN_VALUE;
			if(curMAxIndex<i) {
				for (int m = i; m <= j; m++) {
					if (max < nums[m]) {
						max = nums[m];
						curMAxIndex = m;
					}
				}
				res[i] = max;	
				++i;
				++j;
			}else {
				if (nums[curMAxIndex]<nums[j]) {
					res[i]=nums[j];
					curMAxIndex=j;
				}else {
					res[i]=nums[curMAxIndex];
				}
				++i;
				++j;
			}		
		}
		return res;
	}`

代码如上，自己写的，可能有点长，借鉴的时候可以考虑自己精简一下。

主要思想就是：
  设置2个指针i、j,分别指向滑动窗口的首尾，再设置一个最大值的标识位，第一次是要循环k次的，比较第一个k位滑动窗口中的最大值，并找到位置，之后i,j每次向后滑动一下，都先看一下上一个窗口的最大值是否不在现在这个窗口中了，如果不在就需要重新比较窗口中k个数的最大值是哪个数，如果在，因为窗口中变化的只有新增的末尾的一个数，所以只需要比较一下它和最大数之间谁大即可。

空间复杂度是 O(n)
时间复杂度最坏的情况是每次窗口移动，最大值都不再是窗口中的值，O(nk)
最好的情况是每次都在窗口中O(n)