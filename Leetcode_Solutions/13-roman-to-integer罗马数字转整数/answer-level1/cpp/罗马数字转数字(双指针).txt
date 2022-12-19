### 解题思路
和题解区大佬略有不同，我是从后向前遍历，观察罗马数字的规律可以知道后一个罗马符号和前一个只有两种关系。
```XX```等于，这种情况直接相加，j指针前移。
```IX```小于，这种情况后面减去前面，j指针前移
```XI```大于，这种情况需要改变i指针位置。

### 代码

```cpp
class Solution {
public:
    int romanToInt(string s) {
        map<char, int> _map;
		_map['I'] = 1;
		_map['V'] = 5;
		_map['X'] = 10;
		_map['L'] = 50;
		_map['C'] = 100;
		_map['D'] = 500;
		_map['M'] = 1000;
        
        int i, j;
        int itmp = _map.find(s[s.length()-1])->second;
        int sum = itmp;
        for (i=s.length()-1, j=i-1; j>=0;) {
        	int jtmp = _map.find(s[j])->second;
        	if (itmp == jtmp) {
        		sum += jtmp;
        		j--;
        	}
			else if (itmp > jtmp) {
				sum -= jtmp;
				j--;
			}
			else if (itmp < jtmp) {
				i = j;
				itmp = _map.find(s[i])->second;
			}
        }
        
        return sum;
    }
};
```