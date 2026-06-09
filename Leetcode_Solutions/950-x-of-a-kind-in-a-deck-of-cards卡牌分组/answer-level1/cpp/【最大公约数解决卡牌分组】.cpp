### 解题思路
1，字典数组统计
2，最大公约数判断，如果<2立即返回错误
3，最大公约数：return b==0?a:gcd(b,a%b);

### 代码

```cpp
class Solution {
public:
    int gcd(int a, int b) {
	    return b == 0 ? a : gcd(b, a % b);
    }
    bool hasGroupsSizeX(vector<int>& deck) {
    vector<int> map(10000, 0);
	for (int i = 0; i < deck.size(); i++)
		map[deck[i]]++;
	int x = map[deck[0]];
	for (int i = 0; i < map.size(); i++)
		if (map[i] > 0) {
			x = gcd(x, map[i]);
			if (x < 2)
				return false;
		}
	return true;
    }

};
```