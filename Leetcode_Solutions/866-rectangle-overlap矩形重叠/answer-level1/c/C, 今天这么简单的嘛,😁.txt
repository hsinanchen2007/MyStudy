### 解题思路
![图片.png](https://pic.leetcode-cn.com/8c25a163290b669aebe9248e7ec0b643feb2fdedb7ab3cc174a5c36c28c7e188-%E5%9B%BE%E7%89%87.png)


### 代码

```c

bool isRectangleOverlap(int* rec1, int rec1Size, int* rec2, int rec2Size)
{
	if(rec2[0] < rec1[rec1Size-2] && rec2[1] < rec1[rec1Size-1] && 
	   rec2[rec2Size-2] > rec1[0] && rec2[rec2Size-1] > rec1[1])
	return true;
	else
	return false;
} 
```