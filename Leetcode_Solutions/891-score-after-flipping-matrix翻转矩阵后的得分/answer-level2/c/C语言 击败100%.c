### 解题思路
保证最高位为1
其他位保证1多于0
![image.png](https://pic.leetcode-cn.com/c1babea547326227efa3ad31c953d9c1c79375ffa3cbe03747d5ae507adb873d-image.png)

### 代码

```c
void reverseRow(int** A, int ASize, int* AColSize, int row)
{
	int i;
	for (i = 0; i < AColSize[row]; i++) {
		A[row][i] = A[row][i] == 0 ? 1 : 0;
	}
}

void reverseCol(int** A, int ASize, int* AColSize, int col)
{
	int i;
	for (i = 0; i < ASize; i++) {
		A[i][col] = A[i][col] == 0 ? 1 : 0;
	}
}

bool colOneIsMore(int** A, int ASize, int* AColSize, int col)
{
	int i, cnt1, cnt0;
	for (i = 0, cnt1 = 0, cnt0=0; i < ASize; i++) {
		if (A[i][col] == 1) {
			cnt1++;
		} else {
			cnt0++;
		}
	}
	return cnt1 > cnt0;
}
int trans2int(int** A, int ASize, int* AColSize, int row)
{
	int i, rlt = 0;
	for (i = 0; i < AColSize[0]; i++) {
		rlt = (rlt << 1) + A[row][i];
	}
	return rlt;
}
int matrixScore(int** A, int ASize, int* AColSize){
	int i, cnt;
	int rlt = 0;
	for (i = 0; i < ASize; i++) {
		if (A[i][0] == 0) {
			reverseRow(A, ASize, AColSize, i);
		}
	}
	for (i = 1; i < AColSize[0]; i++) {
		if (colOneIsMore(A, ASize, AColSize, i) == true) {
			continue;
		}
		reverseCol(A, ASize, AColSize, i);
	}
	for (i = 0; i < ASize; i++) {
		rlt += trans2int(A, ASize, AColSize, i);
	}
	
    return rlt;
}
```