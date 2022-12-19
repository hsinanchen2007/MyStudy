### 解题思路
对字符串中的数值从尾到头进行加法计算，将结果推入栈中。
数值计算有三种情况：①"00"型 ②"11"型 ③"01"型
对"00"型，不需要考虑进位。
对"11"型，一定进位。 
对"01"型，考虑上一步计算中是否有进位，如果有，那么当前这一步也需要进位。
进位与否用"append"记录。

当其中一个字符串中的数值计算完毕后，如果另一个字符串还有剩余，那么就继续遍历并将计算结果推入栈中。遍历过程中仍需考虑是否进位。

最后判断首位是否有进位(即判断遍历结束后append是否为1)，若有，则将1推入栈中。

### 代码

```cpp
class Solution {
public:
	string addBinary(string a, string b) {
		int n = a.size() - 1;
		int m = b.size() - 1;
		if (n < m) // n > m,方便后面的收尾
			return addBinary(b, a);
		stack<int> Stack;
		int append = 0; // 记录是否有进位
		while (n >= 0 && m >= 0) {
			if ((b[m] == '1') && (a[n] == '1')) {
				Stack.push(0+append);
				append = 1;
			}
			else if((b[m] == '0') && (a[n] == '0')) {
				Stack.push(0 + append);
				append = 0;	
			}
			else { // "01"型
				if (append == 0) {
					Stack.push(1);
					append = 0;
				}
				else {
					Stack.push(0);
					append = 1;
				}
			}
			n--; m--;
		}

		string res = "";
		while (n >= 0) {
			if (a[n] - 48 + append == 2) {
				Stack.push(0);
				append = 1;
			}
			else {
				Stack.push(a[n] - 48 + append);
				append = 0;
			}
			n--;
		}
		if (append == 1)
			Stack.push(1);

		while (!Stack.empty()) {
			res += to_string(Stack.top());
			Stack.pop();
		}

		return res;
	}
};
```