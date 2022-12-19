### 解题思路
**去括号法则**：括号前面是加号时，去掉括号，括号内的算式不变。括号前面是减号时，去掉括号，括号内加号变减号，减号变加号。

### 代码

```cpp
#include <stack>


#define STATE_ADD	1
#define STATE_MINUS	2

class Solution {
public:
    int calculate(string s) {
		int i = 0;
		int num = 0, sum = 0;
		int state = STATE_ADD;
		std::stack<bool> sign_change;

		for (i = 0; s[i] != '\0'; i++) {
			if (s[i] == ' ')
				continue;

			switch (s[i]) {
				case '(':
					if (state == STATE_ADD) 
						sign_change.push(true);
					else
						sign_change.push(false);
					break;
				case ')':
					sign_change.pop();
					break;
				case '0':
				case '1':
				case '2':
				case '3':
				case '4':
				case '5':
				case '6':
				case '7':
				case '8':
				case '9':
					num = num*10 - '0' + s[i];
					break;
				case '+':
					if (state == STATE_ADD) 
						sum += num;
					else
						sum -= num;

					num = 0;
					if (sign_change.empty() || sign_change.top() == true)
						state = STATE_ADD;
					else
						state = STATE_MINUS;
					break;
				case '-':
					if (state == STATE_ADD)
						sum += num;
					else 
						sum -= num;

					num = 0;
					if (sign_change.empty() || sign_change.top() == true)
						state = STATE_MINUS;
					else
						state = STATE_ADD;
					break;
				default :
					break;
			}
		}
		if (state == STATE_ADD)
			sum += num;
		else 
			sum -= num;
        return sum;
    }
};
```
