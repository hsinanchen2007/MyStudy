### 解题思路
想问下，大家都是双百，都击败了谁？

### 代码

```c
bool isRectangleOverlap(int* rec1, int rec1Size, int* rec2, int rec2Size){
	if ((rec1[0] > rec2[2] && rec1[1] > rec2[3] && rec1[2] < rec2[0] && rec1[3] < rec2[1]) || (rec1[0] < rec2[2] && rec1[1] < rec2[3] && rec1[2] > rec2[0] && rec1[3] > rec2[1]))
		return 1;
	return 0;
}
```