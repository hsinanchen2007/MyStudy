### 解题思路
题目有问题：‘至多’有 h 篇论文分别被引用了至少 h 次，“至多应该去掉”
 思路：
1.很明确h的范围是[0-n],要确定h的值，从小到大的去检测，显然效率太低。
2.可以先对数组排序，然后采用二分法去确定h的值。
3.h满足的条件：h <= 当前文章的引用次数，并且 h >= 前一篇文章的引用次数
4.当前h满足条件，则需要往左寻找是否有更大的h，不满足则右寻找满足的h


[个人博客地址](http://47.101.136.180/)
### 代码

```java
class Solution {
	int[] arr;
	int ans;

	public int hIndex(int[] citations) {
		Arrays.sort(citations);
		arr = citations;

		binary(0, citations.length - 1);

		return ans;
	}

	private void binary(int start, int end) {
		if (start > end) { // 递归结束条件
			return;
		}

		int mid = (start + end) / 2;

		int h = arr.length - mid; // 确定h

		if (h <= arr[mid]) { // h <= 当前文章的引用次数
			ans = h;
			binary(start, mid - 1);
		} else { // 不满足往右查找
			binary(mid + 1, end);
		}
	}
}
```