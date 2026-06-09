### 解题思路
![IMG_20200404_155230.jpg](https://pic.leetcode-cn.com/eea998afe32159d6fa248b464eadc90896b5021ab95b3b45ac433b3fb2ea8ecc-IMG_20200404_155230.jpg)
此处撰写解题思路
例如：（（））（）从左往右数如果每个‘（’加一每个‘）’减一，则有121010；从右往左数‘）’加一，‘（’减一有
                                                         012101从两组数中我发现所有最外一级括号都至少有个0
所以依次循环，每层循环都为最外层的括号赋值就可以得到深度最小的。

### 代码

```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int* maxDepthAfterSplit(char* seq, int* returnSize) {
	int k = 0, j = 0, n = 1, a = strlen(seq), x = 0, r1 = 0, r2 = 0, cnt1 = 0, cnt2 = 0;
	int *q;q=(int*)malloc(sizeof(int)*a);
	for ( j= 0; j < a; j++)
		q[j] = -1;
	while (x != a)
	{
		k = a - 1; j = 0; n++; x = 0; r1 = r2 = 0;
		while (k >= 0)
		{
			if (q[k] == -1 || q[k] == -2)r1 = 1;
			else r1 = 0;
			if (q[j] == -1 || q[j] == -2)r2 = 1;
			else r2 = 0;
			if (r1 == 1) {
				if (seq[k] == ')')cnt1++;
				else
					cnt1--;
				if (cnt1 == 0)q[k]--;
			}
			if (r2 == 1)
			{
				if (seq[j] == '(')cnt2++;
				else cnt2--;
				if (cnt2 == 0)q[j]--;
			}
			k--; j++;
		}
		for (int p = 0; p < a; p++)
		{
			if (q[p] == -2)q[p] = n % 2;//???
			if (q[p] != -1)x++;
		}
	}
    *returnSize=a;
	return q;
}
```