### 解题思路
两步走战略（个人认为要比官方答案更清爽易懂）：
1.转换为字符串并逆序；
2.判断转换后的字符串对应的数值是否越界。

### 代码

```cpp
class Solution {
public:
	int reverse(int x) {
		string str = to_string(x);
        string base = to_string(INT_MIN).substr(1,10);
		str = (str[0] == '-') ? str.substr(1, 10) : str;
        //
        std::reverse(str.begin(), str.end());
        if(str.size() == 10 && (str > base || (str == base && x > 0))){
            return 0;
        }
        return x < 0 ? stoi(str)*(-1):stoi(str);
	}
};
```