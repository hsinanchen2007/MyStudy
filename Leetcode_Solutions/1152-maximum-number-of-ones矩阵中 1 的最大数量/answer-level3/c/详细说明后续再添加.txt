```
int cmp(const void *a, const void *b)
{
	return *((int *)b) - *((int *)a);
}
int maximumNumberOfOnes(int width, int height, int sideLength, int maxOnes)
{
	int	sum = 0;
	int	count[sideLength * sideLength];
	int	index;
	for (int i = 0; i < sideLength * sideLength; i++) {
		count[i] = 0;
	}
	for (int i = 0; i < width; i++) {
		for (int j = 0; j < height; j++) {
			index = sideLength * (i % sideLength) + (j % sideLength);
			count[index]++;
		}
	}
	qsort(count, sideLength * sideLength, sizeof(count[0]), cmp);
	for (int i = 0; i < maxOnes; i++) {
		sum += count[i];
	}
	return(sum);
}
```