### 解题思路
这个题考虑到500的长度，肯定超过long long int了， 所以用转成数字处理肯定会失败。
所以用纯字符串处理，解决除2和+1的操做，+1比较麻烦，要处理进位问题。

### 代码

```cpp
class Solution {
public:
    int numSteps(string s) {
		int step = 0;
		while (s != "1") { // 最后一位为0，除2处理，直接删掉最后一个0就可以了
			if (s.back() == '0') {
				s.pop_back();
				step++;
			}
			else {  // 如果最后一位为1，+1处理，主要是进位的处理。
				int n = s.size();
				s.back() = '0'; // 最后一位先设置为0，因为肯定会进位
				for (int i = n - 2; i >= 0; i--) { //进位判断循环，从倒数第二判断是不是1，如果是1，需要置为0
					if (s[i] == '1') {
						s[i] = '0';
						if (i == 0) {  // 特殊情况，当最高位是1的时候，需要在最高位前再插入一个1。
							s.insert(s.begin(), '1');
						}
					}
					else { //如果碰到0了，那么就置为1，并跳出进位循环
						s[i] = '1';
						break;
					}
				}
				step++;
			}
		}
		return step;
    }
};
```