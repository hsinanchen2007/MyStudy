这道题最粗暴的方法当然是O(n^2)，当然对于medium难度的题目来说，显然不能这么做 这道题要解决的问题是，找寻最大的一组(i,j)，使得Area最大

```
Area = Max(min(height[i], height[j]) * (j-i)) {其中0 <= i < j < height,size()}
```
这里用到了动态规划，基本的表达式: area = min(height[i], height[j]) * (j - i) 使用两个指针，值小的指针向内移动，这样就减小了搜索空间 因为面积取决于指针的距离与值小的值乘积，如果值大的值向内移动，距离一定减小，而求面积的另外一个乘数一定小于等于值小的值，因此面积一定减小，而我们要求最大的面积，因此值大的指针不动，而值小的指针向内移动遍历


```
func maxArea(height []int) int {

	maxArea := 0
	for i, j := 0, len(height)-1; i < j; {
		h := height[i]
		if height[i] > height[j] {
			h = height[j]
		}
		w := j - i
		if h*w > maxArea {
			maxArea = h * w
		}
		if height[i] < height[j] {
			i++
		} else {
			j--
		}
	}
	return maxArea
}
```