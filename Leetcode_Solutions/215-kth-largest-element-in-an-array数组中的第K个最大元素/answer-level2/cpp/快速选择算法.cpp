### 解题思路
使用快速选择算法

### 代码

```cpp
class Solution {
public:
	int findKthLargest(vector<int>& nums, int k) {
		int i = 0;//左边下标
		int j = nums.size() - 1;//右边下标
		int targetIdx = nums.size() - k;//升序排序中需要访问的下标
		while (i <= j) {
			int partitionIdx = partition(nums, i, j);//得到枢轴下标
			if (partitionIdx == targetIdx)//结束条件
				return nums[targetIdx];
			if (targetIdx < partitionIdx)//目标下标在枢轴下标的左边，修改右边界
				j = partitionIdx - 1;
			else//目标下标在枢轴下标的右边，修改左边界
				i = partitionIdx + 1;
		}
		return -1;//找不到，返回0
	}
	int partition(vector<int>& nums, int left, int right) {//分区，返回中间枢轴的下标
		//当访问的仅有一个元素，直接返回
		if (left == right)
			return left;
		int pivot = nums[left];//选取左边第一个元素为枢轴节点
		while (left < right) {
			while (left < right&&nums[right] >= pivot)
				right--;
			//右边找一个小于枢轴的的数值，交换
			nums[left] = nums[right];
			while (left < right&&nums[left] <= pivot)
				left++;
			//左边找一个大于枢轴的的数值，交换
			nums[right] = nums[left];
		}
		nums[left] = pivot;//修改枢轴的值
		return left;//返回中间枢轴的下标
	}
};
int main() {
	Solution s;
	vector<int> v = { 3, 2, 1, 5, 6, 4 };
	int k = 2;
	int result = s.findKthLargest(v, k);
	system("pause");
	return 0;
}
```