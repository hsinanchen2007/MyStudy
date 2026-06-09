### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
private:
	int gcd(int a, int b) {
		if (a%b == 0) { return b; }
		return gcd(b, a%b);
	}
public:
	bool hasGroupsSizeX(vector<int>& deck) {
		if (deck.size() < 2) { return false; }
		int minCount = INT_MAX;
		map<int, int>numCount;
		for (int i = 0; i < deck.size(); i++) {
			if (numCount.find(deck.at(i)) == numCount.end()) {
				numCount.insert(pair<int, int>(deck.at(i), 1));
			}
			else {
				numCount[deck.at(i)]++;
			}
		}
		for (auto ite = numCount.begin(); ite != numCount.end(); ite++) {
			if (minCount == INT_MAX) { minCount = ite->second; }
			else {
				minCount = gcd(minCount, ite->second);
			}
			if (minCount == 1) { return false; }
		}

		return true;	
	}
};
```