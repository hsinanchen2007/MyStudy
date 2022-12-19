### 解题思路
此处撰写解题思路

### 代码

```c
int maximumSwap(int num){
	printf("num %d \n", num);

	int flag[10] = { 0 };
	int cnt = 0;
	int i;
	int ret = num;
	int temp;
	for (i = 0; i < 10; i++) {
		flag[i] = ret % 10;
		printf("flag[i] %d i %d \n", flag[i], i);
		ret = ret / 10;
		printf("ret %d \n", ret);
		if (ret == 0) {
			cnt = i;
			printf("cnt %d \n", cnt);
			break;
		}
	}

	int j;
	int changePos;
	int change = 0;
	for (i = cnt; i >= 0; i--) {
        temp = flag[i];
		for (j = 0; j < i; j++) {
			if (flag[i] < flag[j]) {
				printf("i %d j %d \n", i, j);
				printf("flag[i] %d flag[j] %d \n", flag[i], flag[j]);
				
				flag[i] = flag[j];
				changePos = j;
				change = 1;
			}
		}
		if (change == 1) {
			flag[changePos] = temp;
			break;
		}
	}

	j = 1;
	for (i = cnt; i >= 0; i--) {
		ret = flag[i] * pow(10, i) + ret;
		j++;
	}
	return ret;
}
```