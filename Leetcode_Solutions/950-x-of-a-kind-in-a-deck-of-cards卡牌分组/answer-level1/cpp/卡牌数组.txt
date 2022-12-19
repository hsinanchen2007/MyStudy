### 解题思路
此处撰写解题思路
我的代码效率及其底下，无非是统计每个数出现的次数，然后计算每个数的是否用相同的最大公因数，没有的话，输出错误。

### 代码

```cpp
class Solution {
int gcd(int a, int b){
	for (int i = b; i >= 1; i--) {
		if (a % i == 0 && b % i == 0) return i;

	}
    return 1;
}
public:
bool hasGroupsSizeX(vector<int>& deck) {
	int b[10000] = {0};
	
	vector<int> deck1(b,b+10000);
	for (vector<int>::iterator i = deck.begin(); i != deck.end(); i++) {
		deck1[*i]++;
	}
	sort(deck1.begin(),deck1.end());
	int count = 0;
	for (vector<int>::iterator j = deck1.begin(); j != deck1.end(); j++) {
		if (*j == 1) return false;
		if (*j != 0) {
			int t = *(deck1.begin() + count);
			for (vector<int>::iterator m = deck1.begin()+count; m != deck1.end()-1; m++) {
				if(gcd(*(m + 1),t)<2)
					return false;
			}

		}
		count++;
	}
	return true;
}

};
```