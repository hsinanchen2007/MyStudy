### 解题思路
看二分的解析头炸了，就采用传统的循环方法，感觉效果也不错
![image.png](https://pic.leetcode-cn.com/723bc3db7c40c1ad5b68f95c9c771dbfce0aeff04c294a0dc669930d93ec7802-image.png)
在另一道[154.寻找旋转排序数组中的最小值](https://pic.leetcode-cn.com/c127219380f411a127d355e52062a99d19453c005c6dd4283617f28934b831f7)中
执行耗时如下：
![image.png](https://pic.leetcode-cn.com/fb54ae4332a6355cdd4834959d614b981af02bf1cf155516c88ed59a6204b27d-image.png)

### 代码

```cpp
class Solution {
public:
	int minArray(vector<int>& numbers) {
		if (numbers.empty()) return 0;//特判
		int min = numbers[0];
		for (int i=1;i<numbers.size();i++)
		{
			if (min > numbers[i]) return numbers[i];
		}
		return min;
	}
};
```