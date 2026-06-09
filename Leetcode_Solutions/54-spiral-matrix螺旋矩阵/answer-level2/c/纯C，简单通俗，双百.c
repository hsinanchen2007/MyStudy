![1.png](https://pic.leetcode-cn.com/5e6673ec82e4e76ce1cbc629570382a8dd63be7eb863cda11f5a8d04fae7d442-1.png)

### 解题思路
设置a,b,c,d作为四个顶点，和四个方向，初始向右，a初始为1；
每到达一个顶点，相应的向内收缩一点，并且改变一次方向。

### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* spiralOrder(int** matrix, int matrixSize, int* matrixColSize, int* returnSize){
    if (!matrixSize || 0 == *matrixColSize){
		*returnSize = 0;
		return 0;
	}	
	int a = 1, b = *matrixColSize - 1, c = matrixSize - 1, d = 0, cir = matrixSize*(*matrixColSize);
	int r = 1, l = 0, up = 0, down = 0, i = 0, j = 0, in = 0;
    int *res = (int*)malloc(sizeof(int)*cir);
	while (cir--){
		res[in++] = matrix[i][j];
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
	*returnSize = in;
	return res;
}
```