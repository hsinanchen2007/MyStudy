### 解题思路
此处撰写解题思路

### 代码

```c
bool canPlaceFlowers(int *flowerbed, int flowerbedSize, int n)
{
	int loop;
	int start = -1;
	int end;
	int tmp = 0;

	int sum = 0;
	if (!flowerbed)
		return false;

	for (loop = 0; loop < flowerbedSize; loop++) {
		if (flowerbed[loop] && start == -1)
			start = loop;
		if (flowerbed[loop])
			end = loop;
	}
    
	if (start == -1) {
		if ((flowerbedSize + 1) / 2 >= n)
			return true;
		else
			return false;
	}

    //printf("start %d end %d head %d tail %d\n", start, end, start, flowerbedSize - end - 1);
	for (loop = start; loop <= end; loop++) {
		if (!flowerbed[loop]) {
			tmp++;
		} else {
			sum += (tmp - 1) / 2;
			tmp = 0;
		}
	}
	sum += (start / 2) + (flowerbedSize - end - 1) / 2;
	if (sum >= n)
		return true;

	return false;
}
```