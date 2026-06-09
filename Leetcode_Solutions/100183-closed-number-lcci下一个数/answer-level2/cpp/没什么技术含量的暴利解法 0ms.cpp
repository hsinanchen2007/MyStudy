写了个函数count1，用来计算数字中有几个1，然后就挨个从这个数下面上面去找就好了。
这样子的解法 最差情况应该就是这个数
0111 1111 1111 1111 1111 1111 1111 1111，要找到比他大的那个估计会麻烦点
可能数据不够强大吧。 

```
class Solution {
	int count1(int num) {
		int cnt = 0;
		for (int i = 0; i < 32; i++) {
			if (num & (1 << i)) cnt++;
		}
		return cnt;
	}

public:
	vector<int> findClosedNumbers(int num) {
		int s = count1(num);
		vector<int> res = { -1,-1 };
		for (int i = num + 1; i <= 2147483647; i++) {
			if (count1(i) == s) {
				res[0] = i; break;
			}
		}
		for (int i = num - 1; i >= 0; i--) {
			if (count1(i) == s) {
				res[1] = i; break;
			}
		}
		return res;
	}
};
```
