### 归并排序
归并排序的思路合并两个有序数组。
#### 解法一：
另外创建一个新数组，双指针的做法，将指向数值小的压入新的数组，同时指针前进一位。
#### 解法二：
题设已经说明`nums1`数组有足够大的空间，那么可以直接利用`nums1`数组，无需再创建一个新数组，仍然是双指针的做法，但采用的是倒序的方式。指针`i`,`j`,`k`分别指向`num1`数组`m-1`位置，`num2`数组`n-1`位置和`num1`数组`m+n-1`位置，将`i`,`j`指向数值大的放在`k`位置，同时`i`/`j`前进一位，`k`向前进一位。
```
class Solution {
public:
	void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
		for (int i = m - 1, j = n - 1, k = m + n - 1; k >= 0; --k) {
			if (j < 0 || i >= 0 && nums1[i] > nums2[j])
				nums1[k] = nums1[i--];
			else
				nums1[k] = nums2[j--];
		}
	}
};

```
我果真不适合写题解，写文章啊！
文末推荐LeetCode官方题解：[Merge Sorted Array - LeetCode官方题解](https://leetcode-cn.com/problems/merge-sorted-array/solution/he-bing-liang-ge-you-xu-shu-zu-by-leetcode/)