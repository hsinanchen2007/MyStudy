### 解题思路
![image.png](https://pic.leetcode-cn.com/83acf315825d2d2b2808927dd6d3915d80ffde3c4c800950ba2e4e0fb7abcf7b-image.png)
参考自[@aift](/u/aift/)的思路

### 代码

```cpp
class Solution {
public:
	int strToInt(string str) {
		int res = 0;
		int i = 0;
		int flag = 1;//用来判断是正还是负,1表示正，0表示负
		//1.检查空格
		while (str[i] == ' ') i++;
		//2.检查符号
		if (str[i] == '-') flag = 0;
		if (str[i] == '-' || str[i] == '+') i++;
		//计算数字
		while (i<str.size()&&isdigit(str[i]))//如果i在size范围内1，且1为数字，则进行计算
		{
			int r = str[i] - '0';
			//判断是否溢出
			if (res>INT_MAX/10||(res==INT_MAX/10&&r>7))
				//INT_MAX=2147483647
				//INT_MIN=-2147483648
				//如果res比214748364大，则res加入数字r后，一定越界
				//如果res=214748364,但是r>7，则也发生越界
			{
				return flag ? INT_MAX : INT_MIN;
			}
			res = res * 10 + r;
            i++;
		}
		return flag ? res : -res;
	}
};
```