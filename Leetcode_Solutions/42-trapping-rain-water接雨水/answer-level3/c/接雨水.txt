### 解题思路
使用双指针按照水位高度逐层计算求和再减去所有在水中的柱子体积
### 代码

```c
int trap(int* height, int heightSize) {

	int lo = 0, hi = heightSize - 1;
	int retV = 0;
	int pillarV = 0;
	int curH = 0;
	while (lo < hi) {
		if (height[lo] < height[hi]) {
			if (height[lo] > curH) {
				retV += (height[lo]-curH) * (hi - lo + 1);
				curH = height[lo];
			}
			lo++;
		}
		else if (height[lo] > height[hi]) {
			if (height[hi] > curH) {
				retV += (height[hi]-curH) * (hi - lo + 1);
				curH = height[hi];
			}
			hi--;
		}
		else {
			if (height[hi] > curH) {
				retV += (height[hi] - curH) * (hi - lo + 1);
				curH = height[hi];
			}
			hi--;lo++;
		}
	}
	for (int i = 0; i < heightSize; i++) {
		if (height[i] > curH) {
			pillarV += curH;
		}
		else {
			pillarV += height[i];
		}
	}
	return retV - pillarV;
}
```