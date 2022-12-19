### 解题思路
	做法没什么营养，就等差数列公式推导下，先求出发糖果的次数，剩下不够一轮的就是最后一轮待发的余数
	这里面有一种情况就是第一次都不够发，轮数是0的情况，特殊判断下即可

### 代码

```c
#define MAX_SIZE 10000
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* distributeCandies(int candies, int num_people, int* returnSize) {
	if (candies == 0 || num_people == 0) {
		*returnSize = 0;
		return 0;
	}
	int *rightCandies = (int*)malloc(sizeof(int) * num_people);
	memset(rightCandies, 0, sizeof(int) * num_people);
	int x = 0;
	int flag = 0;
	for (int i = 1; i < MAX_SIZE; ++i) {
		if ((1 + i * num_people) * i * num_people / 2 == candies) {
			x = i;
			flag = 0;
			break;
		}
		if ((1 + i * num_people) * i * num_people / 2 > candies) {
			x = i - 1;
			flag = 1;
			break;
		}
	}
	int candies_remain = 0;
	for (int i = 0; i < num_people; ++i) {
		if (flag == 0) {
			rightCandies[i] = (i + 1 + (x - 1) * num_people + i + 1) * x / 2;
		}
		else {
			if (x) {
				rightCandies[i] = (i + 1 + (x - 1) * num_people + i + 1) * x / 2;
			}		
		}
		
	}
	if (flag == 0) {	
		*returnSize = num_people;
		return rightCandies;
	}
	else {
		if (x) {
			candies_remain = candies - (1 + x * num_people) * x * num_people / 2;
		}
		else {
			candies_remain = candies;
		}
		for (int i = 0; i < num_people; ++i) {
			if (candies_remain - (x * num_people + i + 1) > 0) {
				rightCandies[i] += x * num_people + i + 1;
				candies_remain = candies_remain - (x * num_people + i + 1);
			}
			else {
				rightCandies[i] += candies_remain;
                candies_remain = 0;
                break;
			}		
		}
	}
	*returnSize = num_people;
	return rightCandies;
}
```