1. 先把思维定位到双指针 head = 0;  end = heightSize - 1;
2. 这是后最大面积显而易见 h = min(height[head], height[end]); l = end - hed;  area = h * l
3. 如果将移动 高度较大的指针，无论移到哪里，接下来的面积都小于第二部的area
4. 只有移动，高度较小的指针，才有可能取得到更大的面积

``` c
int maxArea(int* height, int heightSize) {
	// check
	if (!height || heightSize < 2)
		return 0;
	int max_area = 0;
	int head = 0;
	int end = heightSize - 1;
	int h;
	int l;
	while (head != end) {
		l = end - head;
		if (height[head] < height[end]) {
			h = height[head];
			head++;
		} else {
			h = height[end];
			end--;
		}
		max_area = max_area > h * l ? max_area : h * l;
	}
	return max_area;
}
```
