![1.png](https://pic.leetcode-cn.com/449de38730ae96fd3e19e021092bd8edf43e291d2e6948cc9d0f04bb7d61b81e-1.png)


### 解题思路
1、设置flag=0为不接水状态，=1为接水状态；
2、flag=0，height[i+1]>=height[i]时，直接跳过；
3、height[i+1]<height[i]时，如果存在height[i+1]右侧仍然有大于height[i]，直接开始计数；如果没有，取右侧的最大值

### 代码

```c
int trap(int* height, int heightSize){
	if (heightSize < 3)
		return 0;
	int res = 0, i, j, k, t, flag = 0, max = 0;
	for (i = 0; i < heightSize - 2; i++){
		t = 0; max = 0;
		for (j = i + 1; j < heightSize; j++){
			if (height[j] >= height[i] && flag == 0)
				break;
			else if (height[j] < height[i] && flag == 0){
				for (k = j + 1; k < heightSize; k++){
					if (height[k] >= height[i]){
						flag = 1;
						j = i;
						break;
					}
					max = max>height[k] ? max : height[k];
				}
				if (flag == 0 && max > height[j]){
					flag = 1;
					height[i] = max;
					j = i;
				}
			}
			else if (height[j] < height[i] && flag == 1){
				t += height[i] - height[j];
			}
			else if (height[j] >= height[i] && flag == 1){
				flag = 0;
				i = j - 1;
				break;
			}
		}
		res += t;
	}
	return res;
}
```