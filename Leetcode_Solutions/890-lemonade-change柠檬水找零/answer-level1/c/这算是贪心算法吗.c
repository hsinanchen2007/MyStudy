![1.png](https://pic.leetcode-cn.com/a69141a10b1ca3c8929d23fb41dc3102701b5d37c39853e1526b4cd0891624f3-1.png)

### 解题思路
用了一个数组，标记5、10的个数

### 代码

```c
bool lemonadeChange(int* bills, int billsSize){
	if (!billsSize)
		return 1;
	int *t = (int*)calloc(2, sizeof(int));
	for (int i = 0; i<billsSize; i++){
		if (bills[i] == 5)
			t[0]++;
		else if (bills[i] == 10){
			if (t[0] == 0)
				return 0;
			t[0]--;
			t[1]++;
		}
		else{
			if ((t[0] == 0) || (t[1] == 0 && t[0] < 3))
				return 0;
			if (t[1] > 0){
				t[1]--;
				t[0]--;
			}
			else
				t[0] -= 3;			
		}
	}
	return 1;
}
```