不允许用库函数，打表的话时间太长，空间太大

平方数必然为前若干个连续奇数之和，因此可以利用一下

代码：
```
class Solution {
public:
	bool isPerfectSquare(int num) {
		long long ans = 0;
        for(int i = 1 ; ans < num ; i += 2)
            ans += i;
        return ans == num;
	}
};
```
