### 解题思路
逐个递归进行传染上色

![image.png](https://pic.leetcode-cn.com/5b428a309ab615ce2af8f7b12a5a2f4b3bb36c10e064a9a4216b35d087cd91da-image.png)

### 代码

```c
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
void infect(int** image, int imageSize, int* imageColSize, int sr, int sc, int oldColor, int newColor)
{
	if (sr < 0 || sr >= imageSize) {
		return;
	}
	if (sc < 0 || sc >= imageColSize[0]) {
		return;
	}
	
	if (image[sr][sc] == oldColor) {
		image[sr][sc] = newColor;
		inflect(image, imageSize, imageColSize, sr + 1, sc, oldColor, newColor);
		inflect(image, imageSize, imageColSize, sr - 1, sc, oldColor, newColor);
		inflect(image, imageSize, imageColSize, sr, sc + 1, oldColor, newColor);
		inflect(image, imageSize, imageColSize, sr, sc - 1, oldColor, newColor);
	}
	return;
}
int** floodFill(int** image, int imageSize, int* imageColSize, int sr, int sc, int newColor, int* returnSize, int** returnColumnSizes){
	if (image[sr][sc] != newColor) {
		infect(image, imageSize, imageColSize, sr, sc, image[sr][sc], newColor);
	}
	*returnSize = imageSize;
	*returnColumnSizes = imageColSize;
	return image;
}
```