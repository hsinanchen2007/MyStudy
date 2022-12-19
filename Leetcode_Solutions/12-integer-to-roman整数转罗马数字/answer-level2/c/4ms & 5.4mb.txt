### 解题思路
![2.png](https://pic.leetcode-cn.com/9bf6c9542b8d5dfddcfd02ed15e6674f2ca9bfe67d1f5877c02dbec00861bcae-2.png)

莽递归判断深度，后序遍历，得到每一位上的结果。
第一次有个全局变量，进入函数时忘了置零，导致每次test进行累加，后修改为局部static变量成功A过。
### 代码
```c
/*
 * @lc app=leetcode.cn id=12 lang=c
 *
 * [12] 整数转罗马数字
 */

 // @lc code=start
#include<stdio.h>
#include<string.h>
void dealit(char* T, int num, int deep);

char* intToRoman(int num) {
    static char Ans[20] = { 0 };
    Ans[0] = '\0';
	dealit(Ans, num, 1);
	return Ans;
}
void dealit(char* T, int num, int deep) {
	if (num)
	{
		deep++;
		dealit(T, num / 10, deep);
		deep--;
		char temp[8] = { 0 };//将每一位的结果存到这个临时指针中
		//判断搜索深度
		switch (deep)
		{
		case 1:
			if ((num % 10) <=3  && (num % 10) != 0) {
				for (int i = 0; i < (num % 10); i++)
					temp[i] = 'I';
			}else if ((num % 10) == 4) {
				temp[0] = 'I';
				temp[1] = 'V';
			}else if ((num % 10) == 5) {
				temp[0] = 'V';
			}else if ((num % 10) < 9 && (num % 10) >5) {
				temp[0] = 'V';
				for (int i = 1; i <= ((num % 10) - 5); i++)
					temp[i] = 'I';
			}else if ((num % 10) == 9) {
				temp[0] = 'I';
				temp[1] = 'X';
			}
			break;
		case 2:
			if ((num % 10) < 4 && (num % 10) != 0) {
				for (int i = 0; i < (num % 10); i++)
					temp[i] = 'X';
			}
			else if ((num % 10) == 4) {
				temp[0] = 'X';
				temp[1] = 'L';
			}
			else if ((num % 10) == 5) {
				temp[0] = 'L';
			}
			else if ((num % 10) < 9 && (num % 10) >5) {
				temp[0] = 'L';
				for (int i = 1; i <= (num % 10) - 5; i++)
					temp[i] = 'X';
			}
			else if ((num % 10) == 9) {
				temp[0] = 'X';
				temp[1] = 'C';
			}
			break;
		case 3:
			if ((num % 10) < 4 && (num % 10) != 0) {
				for (int i = 0; i < (num % 10); i++)
					temp[i] = 'C';
			}
			else if ((num % 10) == 4) {
				temp[0] = 'C';
				temp[1] = 'D';
			}
			else if ((num % 10) == 5) {
				temp[0] = 'D';
			}
			else if ((num % 10) < 9 && (num % 10) >5) {
				temp[0] = 'D';
				for (int i = 1; i <= (num % 10) - 5; i++)
					temp[i] = 'C';
			}
			else if ((num % 10) == 9) {
				temp[0] = 'C';
				temp[1] = 'M';
			}
			break;
		case 4:
			if ((num % 10) < 4 && (num % 10) != 0) {
				for (int i = 0; i < (num % 10); i++)
					temp[i] = 'M';
			}
			break;
		default:
			break;
		}
		strcat(T, temp);//临时指针加到结果上

	}

}
// @lc code=end


```