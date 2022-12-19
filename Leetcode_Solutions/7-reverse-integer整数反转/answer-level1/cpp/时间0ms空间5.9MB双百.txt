```
class Solution {
public:
	int reverse(int x) {
		long res = 0;
		int yushu;
		while (x != 0) {
			yushu = x % 10;
			x = x / 10;
			if (res == 0 && yushu == 0) continue;
			res = res * 10 + yushu;
			if (res<INT_MIN || res>INT_MAX) return 0;
		}	
		return res;
	}
};
```
- 之前遇到类似题目都是用空间换算法，也就是用列表存每个位置数字。
- 但是用算法速度更快
- 如下是关键代码，表达的意思是遇到1200这样的后缀0则跳过即可
```
if (res == 0 && yushu == 0) continue;
```
