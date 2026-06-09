### 解题思路
把胃口和饼干按从小到大排序，然后从小到大分配饼干即可

![image.png](https://pic.leetcode-cn.com/e462fbff4e082f6a54db39f86a8709407e99d8042d28a2f2fc7ea80838b3cef4-image.png)

### 代码

```c
int cmp(const int *a, const int *b)
{
	return *a > *b;
}

int findContentChildren(int* g, int gSize, int* s, int sSize){
	int gi = 0;
	int si = 0;
	int cnt = 0;
	qsort(g, gSize, sizeof(int), cmp);
	qsort(s, sSize, sizeof(int), cmp);
	while (si < sSize && gi < gSize) {
		if (g[gi] <= s[si]) {
			cnt++;
			gi++;
			si++;
		} else {
			si++;
		}
	}
	return cnt;
}
```