![1.png](https://pic.leetcode-cn.com/eac51112358bc033794eab50e77720d56cc2edebfb113c3a8d357b0ef8dfd1b7-1.png)

### 解题思路
按年、月、日，计算到1971.1.1之间的天数，取余

### 代码

```c
char * dayOfTheWeek(int day, int month, int year){
	char *res[7] = { "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday" };
	int start = 4;
	for (int y = 1971; y < year; y++)
		if ((y % 4 == 0) && y != 2100)
			start += 366;
		else
			start += 365;	
	for (int m = 1; m < month; m++){
		if (m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10)
			start += 31;
		else if (m == 2){
			if ((year % 4 == 0) && year != 2100)
				start += 29;
			else
				start += 28;
		}
		else
			start += 30;
	}
	start += day;
	start %= 7;
	return res[start];
}
```