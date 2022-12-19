![1.png](https://pic.leetcode-cn.com/ad5495478675e8e876dfda0fc0099efe9ed1d2fd88aa3cca82742f8a82352519-1.png)

### 解题思路
设置a,b,c,d作为四个顶点，和四个方向，初始向右，a初始为1；
每到达一个顶点，相应的向内收缩一点，并且改变一次方向。

### 代码

```c
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** generateMatrix(int n, int* returnSize, int** returnColumnSizes){
	int **res = (int**)malloc(sizeof(int*)*n);
	for (int i = 0; i < n; i++){
		res[i] = (int*)malloc(sizeof(int)*n);
		(*returnColumnSizes)[i] = n;
	}
	int a = 1, b = n - 1, c = n - 1, d = 0, cir = n*n;
	int r = 1, l = 0, up = 0, down = 0, i = 0, j = 0, num = 1;
	while (cir--){
		res[i][j] = num++;
		if (r){
			if (j == b){
				b--;
				r = 0;
				down = 1;
				i++;
			}
			else
				j++;
		}
		else if (l){
			if (j == d){
				d++;
				l = 0;
				up = 1;
				i--;
			}
			else
				j--;

		}
		else if (up){
			if (i == a){
				a++;
				up = 0;
				r = 1;
				j++;
			}
			else
				i--;

		}
		else if (down){
			if (i == c){
				c--;
				down = 0;
				l = 1;
				j--;
			}
			else
				i++;
		}
	}
	*returnSize = n;
	return res;
}
```