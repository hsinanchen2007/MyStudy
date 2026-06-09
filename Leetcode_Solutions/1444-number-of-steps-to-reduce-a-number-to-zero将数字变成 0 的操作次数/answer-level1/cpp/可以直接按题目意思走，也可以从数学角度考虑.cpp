方法一：直接按题目要求产生代码。
```
class Solution {
public:
	int numberOfSteps(int num) {
		int res = 0;
		while (num != 0) {
			if (num % 2 == 1) {
				res++;
				num--;
			}
			else {
				res++;
				num /= 2;
			}
		}
		return res;
	}
};
```
方法二：如果按数学方法走，二进制有1计数就+2，有0就+1，最后计数-1（因为最后num变为1后只需要1步变为0，而不是两步）。这样做存在个问题，当num一开始就是0的时候结果会返回-1，而不是0，所有0要另外判断。
```
class Solution {
public:
	int numberOfSteps(int num) {
		if (num == 0)
			return 0;
		int res = 0;
		while (num != 0) {
			if (num % 2 == 1)
				res += 2;
			else
				res++;
			num /= 2;
		}
		return res - 1;
	}
};
```

当然以上两个方法中，如果把`num % 2 == 1`改成`num & 1 == 1`，`num /= 2`改成`num >>= 2`，也许会更快。

