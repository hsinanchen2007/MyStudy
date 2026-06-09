### 解题思路
关键在于变换之后的数和原来的数比较。
一般都是通过%10从低位比起，这样变化之后的数是倒序，不好直接和原数比较。
如果在变化的同时，也把原数倒序，就好比较多了。
![image.png](https://pic.leetcode-cn.com/e0f2ae3bcae8271534591741331ac5b536afc93e4fddf2daca10a6eb5c86b610-image.png)

### 代码

```c
bool isGood(int n)
{
	int cur;
	int rCur;
	int rN = 0;
	int rNewN = 0;
	while(n > 0) {
		cur = n % 10;
		switch (cur) {
			case 0:
			case 1:
			case 8:
				rCur = cur;
				break;
			case 2:
				rCur = 5;
				break;
			case 5:
				rCur = 2;
				break;
			case 6:
				rCur = 9;
				break;
			case 9:
				rCur = 6;
				break;
			default:
				return false;
		}
		rN = rN * 10 + cur;
		rNewN = rNewN * 10 + rCur;
		n /= 10;
	}
	if (rN == rNewN) {
		return false;
	}
	return true;
}

int rotatedDigits(int N){
	int i;
	int cnt = 0;
	for (i = 1; i <= N; i++) {
		if (isGood(i) == true) {
			cnt++;
		}
	}
	return cnt;
}
```