### 解题思路
1、用数组统计各个重量的人数
2、用重量匹配法，遍历数组，匹配重量和小于/等于limit的组合
3、未能匹配的人 直接分配救生艇

### 代码

```c

#define DBG
 
int numRescueBoats(int *people, int peopleSize, int limit)
{
	int i, j, boat, *remanent_height, remanent_height_tmp, tmp;

	if (people == NULL || peopleSize == 0) {
		return 0;
	}

	remanent_height = (int *)malloc(sizeof(int) * limit);
	if (remanent_height == NULL) {
		return 0;
	}

	boat = 0;
	DBG("limit %d, peopleSize %d\n", limit, peopleSize);
	memset(remanent_height, 0, sizeof(int) * limit);
	// for (i = 0; i < peopleSize; i++) {
		// remanent_height[i] = 0;
	// }

	for (i = 0; i < peopleSize; i++) {
		/* XXX: 这里是和的关系, 不是取余 5 % 2 = 1 */
		remanent_height_tmp = limit - people[i];
		DBG("people[%d] %d, remanent height %d, \t", i, people[i], remanent_height_tmp);
		if (remanent_height_tmp == 0) {
			boat++;
			DBG("Get boat, limit %d == people[%d]\n", limit, people[i]);
		/* 当前poeple[i]的重量已经是前面有人计算剩余的 */
		} else if (remanent_height[people[i]]) {
			remanent_height[people[i]]--;
			boat++;
			DBG("Get boat: remanent_height[people[%d] %d] %d, \n", i, people[i], remanent_height[people[i]]);
		} else {
			remanent_height[remanent_height_tmp]++;
			DBG("Stats: remanent_height[%d] %d, \n", remanent_height_tmp, remanent_height[remanent_height_tmp]);
		}
	}

	for (j = 0 ; j < limit; j++) {
		DBG("reAssign: remanent_height[%d] %d, boat %d\n", j, remanent_height[j], boat);
		if (remanent_height[j] == 0) {
			continue;
		}

		/* 重新组合 j <--> (0 ~ limit - j) */
		i = ((limit - j) > (j + 1) ? (limit - j) : (j + 1));
		for (; i < limit; i++) {
			DBG("reAssign: remanent_height[%d] %d <<--->>  remanent_height[%d] %d, boat %d\n", j, 
				remanent_height[j], i, remanent_height[i], boat);
			if (remanent_height[j] < remanent_height[i]) {
				boat += remanent_height[j];
				remanent_height[i] -= remanent_height[j];
				remanent_height[j] = 0;
				break;
			} else {
				boat += remanent_height[i];
				remanent_height[j] -= remanent_height[i];
				remanent_height[i] = 0;
			}
		}
		if (remanent_height[j] > 0) {
			/* 重量超过一半的人, 直接占用一条船 */
			/* XXX: 这里要用小于号, 才能用剩余重量表示 真实体重 */
			if (j <= limit / 2) {
				boat += remanent_height[j];
			} else {
				/* 重量小于一半的人, 二人用一条船 */
				if (remanent_height[j] % 2 == 0) {
					boat += remanent_height[j] / 2;
				} else {
					boat += (remanent_height[j] / 2 + 1);
				}
			}
			DBG("Finish reAssign: remanent_height[%d] %d, boat %d\n", j, remanent_height[j], boat);
			remanent_height[j] = 0;
		}
	} 

	free(remanent_height);

	return boat;
}
```