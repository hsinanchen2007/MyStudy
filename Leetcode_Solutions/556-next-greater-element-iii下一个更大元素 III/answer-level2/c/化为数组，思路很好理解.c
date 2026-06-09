###
所求结果有32位限制需要注意。
每一位进数组，找到尽可能低位做交换，最后排序使得数满足最小且大于n。
//-------author:PeanurLiu----------//

```c
int nextGreaterElement(int n){

    int *ans = (int *)malloc(sizeof(int) * 12);
    int i = 0;
    while (n) {
        ans[i++] = n % 10;
        n /= 10;
    }
    int flag = 1, index = 12, Swapj, Swapk;
    for (int j = 0; j < i - 1; j++) {
		if (j >= index)  break;
//		printf("ENter\n");
        for (int k = j + 1; k < i; k++) {
            if (ans[j] > ans[k]) {
                flag = 0;
				if (k < index) {
                    index = k;
					Swapj = j;
					Swapk = k;
				}
                break;
            }
        }
    }
    if (flag)  return -1;
	int tmp = ans[Swapj];
	ans[Swapj] = ans[Swapk];
	ans[Swapk] = tmp;

	for (int j = 0; j < (Swapk - 1); j++) {
		for (int k = j + 1; k < Swapk; k++) {
			if (ans[j] < ans[k]) {
				int tmp = ans[j];
				ans[j] = ans[k];
				ans[k] = tmp;
			}
		}
	}
    int res = 0;
    for (int j = i - 1; j >= 0; j--) {//重构
        if (res > 200000000)  return -1; //要得的数若大于32位上限，返回-1
        res = res * 10 + ans[j];
    }
    return res;
}
```