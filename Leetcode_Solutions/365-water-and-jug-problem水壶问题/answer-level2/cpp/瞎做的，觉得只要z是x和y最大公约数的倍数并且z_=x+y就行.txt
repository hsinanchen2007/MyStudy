瞎做的，觉得只要z是x和y最大公约数的倍数并且z<=x+y就行。不知道原因，由裴蜀定理可以得到z是x和y最大公约数的倍数是解为true的必要条件，很明显z<=x+y也是必要条件。那充分性怎么证明呢？求大佬解答为什么z是最大公约数倍数就一定可以成功，倒水的中间过程肯定不会超过容积吗？

```
class Solution {
private:
	int gcd(int x, int y) {
		if (x == 0)
			return y;
		if (y == 0)
			return x;
		int z = y;
		while (x % y != 0){
			z = x % y;
			x = y;
			y = z;
		}
		return z;
	}

public:
	bool canMeasureWater(int x, int y, int z) {
		int g = gcd(x, y);
		if (g == 0)
			return !z;
		if (z % g == 0 && (z <= x + y))
			return true;
		return false;
	}
};
```
