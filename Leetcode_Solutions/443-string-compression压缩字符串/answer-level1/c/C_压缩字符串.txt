### 解题思路
一个写指针，两个统计指针
因为题目给出了字符数量在0~1000之间，所以数字转字符串比较好处理，注意当只有1个字符的时候，是不需要再写数字进去的。
参考https://leetcode-cn.com/problems/string-compression/solution/cyu-yan-shuang-zhi-zhen-by-cl0udchun/
### 代码

```c
int compress(char* chars, int charsSize) {

	int write = 0, low = 0, high = 0;
	int temp[4] = { 0 };
	while (high < charsSize)
	{
		while (high < charsSize&&chars[low] == chars[high])++high;
		chars[write++] = chars[low];
		int times = high - low;
		if(times!=1)
		{
			for (int i = 3; i >= 0; --i)
		    {
			    temp[i] = times % 10;
			    times /= 10;
		    }
		    int iter = 0;
		    while (temp[iter] == 0)++iter;
		    while (iter < 4)chars[write++] = temp[iter++] + '0'; 
		}
		low = high;
	}
	return write;
}
```