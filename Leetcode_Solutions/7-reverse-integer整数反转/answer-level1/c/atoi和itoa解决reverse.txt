### 解题思路
我去，我的边界问题写得乱糟糟的
思路：
先用itoa得到数字的数组，然后将数组倒叙存储，再用atoi得到reverse。
边界判别的话，可以将逆序的数组切割成前半段和后半段，
再用atoi得到两个小的整数比较。


### 代码

```c
int reverse(int x) {
	char buf[14];
	char ret[14];
	char min[6], max[6];
	int mn, mx;
	int len;
	int t = 0;
	int x1 = 0;

    if (x == -2147483648)	return 0;
	if (x < 0)	x1 = -x;
	else x1 = x;
	sprintf(buf, "%d", x1);
	len = strlen(buf);
	//printf("buf=%s,len=%d\n", buf, len);
	//数组逆序
	for (int i = 0; i < len; i++) {
		ret[i] = buf[len - 1 - i];
		ret[i + 1] = '\x0';
	}
	//判断溢出
	if (len > 10)	return 0;
	else if (len == 10) {
		for (int i = 0; i < 5; i++) {
			min[i] = ret[i];
			min[i + 1] = '\x0';
			max[i] = ret[i + 5];
			max[i + 1] = '\x0';
		}
		mn = atoi(min);
		mx = atoi(max);
		if (mn > 21474) return 0;
		else if (mn == 21474 && mx > 83648) return 0;
		else if (mn == 21474 && mx == 83648 && x > 0)	return 0;
	}
	t = atoi(ret);
	if (x < 0)	t = -t;
	return t;
}
```