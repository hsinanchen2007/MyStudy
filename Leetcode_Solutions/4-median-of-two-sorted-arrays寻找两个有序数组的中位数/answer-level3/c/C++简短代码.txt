其实在拿到这个题的时候我看到困难一下子内心紧张，首先我没有想拿我不是很熟练的C++去做这个题，但是我尝试着C语言去做
尽管尽量压缩，代码还是很冗长，主要体现在动态申请两个数组的长度，然后依次将这两个数组的值放入，最后将数组排序寻找。
其实思路很简洁明了，但是这个代码真的实现起来很是难整，不光光是时空间复杂度的问题，就单单是排序，你就实现很长的时间，并且最后找中位数更是一件麻烦事。但是换到C++上，我们有容器可以很轻松实现这个数组增长问题，并且在我们的库函数里面有排序的函数可以直接调用，我们最终只需要判断个数的奇偶算就行，可以说一下子将代码精简了很多倍。总体评价，思想很好想，但是想用纯C实现很麻烦，其他语言更精简一些。
代码奉上
class Solution {
public:
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		vector<int>Add(nums1.begin(),nums1.end());
		Add.insert(Add.end(),nums2.begin(), nums2.end());
		sort(Add.begin(), Add.end());
		if (Add.size() % 2 == 0)
		{
			return (double)(((Add[(Add.size() / 2)] + Add[(Add.size() / 2 - 1)]))/2.0);
		}
		else
			return (double)(Add[(Add.size() / 2)]);
	}
};