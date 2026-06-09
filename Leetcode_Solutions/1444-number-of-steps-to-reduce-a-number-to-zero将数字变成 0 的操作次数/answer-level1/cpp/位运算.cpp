### 解题思路
看到题目的内容就感觉这个题是位运算。但位运算的方法不熟，就看了一些题解，发现“num&1”这个操作非常好用，就模仿其他题解写了一个。

### 代码

```cpp
class Solution {
public:
int numberOfSteps(int num) {
	if (num == 0)
		return 0;
	int count = 0;
	while (num)
	{
		if(num &1)
			count++;
		count++;
		num = num >> 1;
	}
	count--;
	return count;
}
};
```