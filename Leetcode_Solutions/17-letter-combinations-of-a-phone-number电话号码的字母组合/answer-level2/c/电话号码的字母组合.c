![绘图1.jpg](https://pic.leetcode-cn.com/2213096ab8e16ef58f994ea20bec8876ed207f19819c83dd075fe7590d6daa92-%E7%BB%98%E5%9B%BE1.jpg)
上图输入是“23”
![绘图2.jpg](https://pic.leetcode-cn.com/6c5506a33f236167f9677f773064b2505a8a71df8a02a421a577aff8f764d2e6-%E7%BB%98%E5%9B%BE2.jpg)
上图输入是“29”
![绘图3.jpg](https://pic.leetcode-cn.com/84b2f2a46de700f5a68fb25891a3b85b0284cf152638d1279b7f2fa3ecc5fa8d-%E7%BB%98%E5%9B%BE3.jpg)

这里的思路是：按照图3的表格去填充每个位置上对应的字母，最后补上“\0”；图三中数列为ret[i][j]中j的值，而横列为i的值；用digits_num[]去记录倒序每层的增加的字母数，
注意这里是倒序记录的，方便后面计算需要循环的次数和重复的次数，因为这里面“2,3,4,5,6,8”包含了三个字母而“7,9”包含了四个字母，采用倒序记录的方式方便后续计算；
填图三表格是按照行列，一行一行的去填写，每一行都需要计算当前需要循环的次数，当前层有多少字母以及每个字母需要重复的次数；
以图一举例，abc需要循环的次数为1，当前层包含三个字母，每个字母需要重复三次，因此填入表格为aaabbbccc，以此类推下一行就是defdefdef；
这里需要注意的就是重复次数的计算方式！



```
char ** letterCombinations(char * digits, int* returnSize){
    
    *returnSize = 0;
	if (strlen(digits) == 0)
		return NULL;

	char *map[8] = { "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };
	int length = strlen(digits);

	int *digits_num = (int *)malloc(sizeof(int) * (length + 1));
	int digits_sum = 1;
	digits_num[0] = 1;
	for (int i = (length - 1), j = 1; i >= 0; i--)
	{
		if (digits[i] == '2' || digits[i] == '3' || digits[i] == '4' ||
			digits[i] == '5' || digits[i] == '6' || digits[i] == '8')
			digits_sum *= 3;
		if (digits[i] == '7' || digits[i] == '9')
			digits_sum *= 4;
		digits_num[j++] = digits_sum;
	}
	*returnSize = digits_sum;

	char **ret = (char **)malloc(sizeof(char *) * digits_sum);
	for (int i = 0; i < digits_sum; i++)
		ret[i] = (char *)malloc(sizeof(char) * (length + 1));
    
	for (int i = 0; i < length; i++)
	{
		int index = 0;
		for (int k = 0, j = 0; k < (digits_num[length] / digits_num[length - i]); k++) //循环
		{
			int n = 0;
			for (; n < (digits_num[length - i] / digits_num[length - 1 - i]); n++) //当前层有多少个字母
			{
				for (; j < ((n + 1) * (digits_num[length - 1 - i]) + index * (digits_num[length - 1 - i]) * (digits_num[length - i] / digits_num[length - 1 - i])); j++) //重复
				{
					ret[j][i] = map[digits[i] - '2'][n];
                    //printf("ret[%d][%d] = %c\t", j, i, ret[j][i]);
				}				
			}
			index++;
		}
	}
    for (int i = 0; i < digits_sum; i++)
    {
		ret[i][length] = '\0';
    }
    
    free(digits_num);
    return ret;
}
```
