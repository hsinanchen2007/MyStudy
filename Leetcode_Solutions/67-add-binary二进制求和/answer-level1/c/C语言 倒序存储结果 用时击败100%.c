### 解题思路
采用倒序存储结果，不需要再分析是否有进位

![image.png](https://pic.leetcode-cn.com/25c12ba816ee664f11f815f0197e351a0294032dc7056ddd3a2778a55d7aae69-image.png)


### 代码

```c
char * addBinary(char * a, char * b){
	int i;
	char tmp;
	int ai, bi;
	int ac, bc, carry, sum;
	char *rlt = NULL;
	int ri;
	ai = strlen(a) - 1;
	bi = strlen(b) - 1;
	rlt = (char*)calloc(ai > bi ? ai + 3 : bi + 3, sizeof(char));
	if (rlt == NULL) {
		return NULL;
	}
	carry = 0;
	ri = 0;
	while (ai >= 0 || bi >= 0 || carry != 0) {
		ac = ai >= 0 ? a[ai] - '0' : 0;
		bc = bi >= 0 ? b[bi] - '0' : 0;
		sum = ac + bc + carry;
		rlt[ri] = sum % 2 + '0'; /* 倒序存储 */
		carry = sum / 2;
		ai--;
		bi--;
		ri++;
	}
	for (i = 0; i < ri / 2; i++) { /* 结果反序 */
		tmp = rlt[i];
		rlt[i] = rlt[ri - 1 - i];
		rlt[ri - 1 - i] = tmp;
	}
	return rlt;
}
```