### 解题思路
采用取模操作，循环累加

![image.png](https://pic.leetcode-cn.com/c497331f59625e2b411c489cdb603058a222602048f19a56e95a3bcc07878f0f-image.png)


### 代码

```c
int tribonacci(int n){
	int i;
	int t[3] = {0, 1, 1};
	if (n < 3) {
		return t[n];
	}
	for (i = 3; i <= n; i++) {
		t[i % 3] = t[0] + t[1] + t[2]; /* 不搬移的关键在这里 */
	}
	return t[n % 3];
}
```