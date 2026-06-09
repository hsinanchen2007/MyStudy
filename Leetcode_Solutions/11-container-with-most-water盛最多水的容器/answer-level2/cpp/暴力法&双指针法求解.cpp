### 解题思路
双指针法：
	1.首尾各一指针，短指针所指元素为矩形的高，两指针间的距离为矩形的宽；
	2.比较两指针所指元素，移动较“短”的指针。（因为矩形的的高是由较短指针所指元素决定的，当距离缩小时，只有矩形高变大才有可能加大面积，所以移动较“短”的指针；
	3.返回最大的面积。
注：
//	for (beg; beg != height.end() - 1; beg++) {
//		for (auto beg1 = beg + 1; beg1 != height.end(); beg1++) {
//			auto d = beg1 - beg;
//			aera = max(aera, min(*beg, *beg1)*d);
//  return aera;
使用暴力法求解时，报错： no matching function for call to 'max(int&, long int)' ，可是在双指针法中max函数没问题呀，咋回事？

### 代码

```cpp
class Solution {
public:
int maxArea(vector<int>& height) {
	int aera = 0;
	int i = 0;
	int j = height.size() - 1;  //size_type
	while (i < j) {
		aera = max(aera, min(height[i], height[j])*(j - i));
		if (height[i] < height[j])
			i++;
		else
			j--;
	}
	return aera;
}


};
```