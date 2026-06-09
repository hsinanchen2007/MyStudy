### 解题思路

思路：容器末位开始循环+1，满足进位时将当前位置0，进入下一次循环。如遇到未满足进位条件直接跳出循环并返回vector容器。
如果直到循环结束进位条件仍然满足，则需要在第一位插入1。
![20200401181739.png](https://pic.leetcode-cn.com/cd76ac76d4127ef4ae49b5f4e3cd9f21bc9fae38ada56162739225f25533fc07-20200401181739.png)

### 代码

```cpp
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int dSize = digits.size();	
	    for (int i = dSize - 1; i >= 0; i--)
	    {
		    digits[i] += 1;
		if (digits[i]!=10)
		{
			return digits;
			break;
		}
		else
		{
			digits[i] = 0;
		}
	}
	digits.insert(digits.begin(), 1);
	return digits;
    }
};
```