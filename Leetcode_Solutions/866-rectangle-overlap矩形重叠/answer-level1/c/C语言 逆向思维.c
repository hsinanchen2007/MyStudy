### 解题思路
	正向去判断比较麻烦，很多种情况要考虑，很容易遗漏，此处的方法是通过求不相交的情况，反过来就是相交的情况（看官方题解才想到。。）
	A矩阵和B矩阵判断其中一个四个方向即可。

### 代码

```c
bool isRectangleOverlap(int* rec1, int rec1Size, int* rec2, int rec2Size) {
	if (rec1 == NULL || rec1Size == 0 || rec2 == NULL || rec2Size == 0) {
		return false;
	}
	int rec1x1 = rec1[0];
	int rec1y1 = rec1[1];
	int rec1x2 = rec1[2];
	int rec1y2 = rec1[3];

	int rec2x1 = rec2[0];
	int rec2y1 = rec2[1];
	int rec2x2 = rec2[2];
	int rec2y2 = rec2[3];

	if (rec1x2 <= rec2x1 || rec1y1 >= rec2y2 || rec1y2 <= rec2y1 || rec1x1 >= rec2x2) {
		return false;
	}
	else {
		return true;
	}
}
```