### 解题思路
利用向x，y轴的投影关系判断是否重叠。

### 代码

```c
bool isRectangleOverlap(int* rec1, int rec1Size, int* rec2, int rec2Size)
{
	if (rec1 == NULL || rec2 == NULL) {
		return false;
	}
	
	bool recX = rec1[2] <= rec2[0] || rec2[2] <= rec1[0];
	bool recY = rec1[3] <= rec2[1] || rec2[3] <= rec1[1];
	return !(recX || recY);
}
```