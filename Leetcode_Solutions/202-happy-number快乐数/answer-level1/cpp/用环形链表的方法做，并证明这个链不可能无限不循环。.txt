如果得出的下一个数为1，则返回true；如果得出的下一个数曾经得到过，说明产生了循环，由于前面的数中没有1，所以返回false；否则，继续计算下一个数。
然后这个思路存在个问题，如果产生循环也就罢了，但如果没有产生循环，怎么知道这个链有没有可能无限不循环呢？
证明如下：
设初始的n为k位数，那么我们有下一个n<=81k。
当k=1时，n<=81，即下一个n最多为两位数。
当k=2时，n<=162，即下一个n最多为三位数。
当k>=3时，n<=81k<100k，这个100k的位数为2+⌈lgk⌉，由于k>=3，所以2+⌈lgk⌉<=k。因此下一个n最多为k位数。
综上我们可以发现一个k位数n的下一个数最多为max(3,k)位数，即计算到的n有个上限且这个上限不超过3位数或者k位数。
由于计算到的n都是整数，所以n的取值范围是有限的，因此不可能出现无限不循环的链。

```C++ []
class Solution {
public:
	bool isHappy(int n) {
		unordered_set<int> s;
		while (n != 1) {
			if (!s.insert(n).second)
				return false;
			get_next_num(n);
		}
		return true;
	}
	void get_next_num(int& n) {
		int sum = 0;
		while (n) {
			sum += pow(n % 10, 2);
			n /= 10;
		}
		n = sum;
	}
};
```
