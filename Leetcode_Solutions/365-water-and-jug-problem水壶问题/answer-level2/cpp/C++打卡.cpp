### 解题思路
看了题解后才明白Orz

### 代码

```cpp
//方法一：深度优先搜索
using STATE = pair<int, int>;

class Solution {
public:
	bool canMeasureWater(int x, int y, int z) {
		if (z<0 || z>x+y) { return false; }
		queue<STATE> myQueue;
		myQueue.push(STATE(0, 0));
		auto hash_function = [](const STATE& state) {return state.first * 1001 + state.second; };
		unordered_set<STATE, decltype(hash_function)> mySet(0, hash_function);
		while (myQueue.empty() == false) {
			STATE cur = myQueue.front();
			myQueue.pop();
			if (mySet.find(cur) != mySet.end()) {
				continue;
			}
			mySet.emplace(cur);
			if (cur.first == z || cur.second == z || cur.first + cur.second == z) { return true; }

			//向first容器中加满水
			myQueue.push(STATE(x, cur.second));
			//向second容器中加满水
			myQueue.push(STATE(cur.first, y));
			//将first容器中水清空
			myQueue.push(STATE(0, cur.second));
			//将second容器中水清空
			myQueue.push(STATE(cur.first, 0));
			//把first容器中的水倒入second容器（倒满或倒空终止）
			if (cur.first >= (y - cur.second)) {
				myQueue.push(STATE(cur.first - (y - cur.second), y));
			}
			else {
				myQueue.push(STATE(0, cur.second + cur.first));
			}
			//把second容器中的水倒入first容器（倒满或倒空终止）
			if (cur.second >= (x - cur.first)) {
				myQueue.push(STATE(x, y - (x - cur.first)));
			}
			else {
				myQueue.push(STATE(cur.first + cur.second, 0));
			}
		}
		return false;
	}
};

//方法二：数学(贝祖定理)
//ax+by=z有解当且仅当 z 是 x, y的最大公约数的倍数
class Solution {
private:
	int gcd(int a, int b) {
		if (a%b == 0) { return b; }
		return gcd(b, a%b);
	}
public:
	bool canMeasureWater(int x, int y, int z) {
		if (z<0 || z>x + y) { return false; }
		if (x == 0 || y == 0) { return z == 0 || z == x + y; }
		if (z%gcd(x, y) == 0) {
			return true;
		}
		else {
			return false;
		}
	}
};
```